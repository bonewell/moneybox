#include "mongocommand.h"

#include <mongocxx/exception/bulk_write_exception.hpp>

#include "model/field.h"

namespace model::db {

void MongoCommand::entity(const std::string& name) {
    entity_ = name;
}

void MongoCommand::where(const std::string& name, const Variant& value) {
    std::visit([&](auto&& arg) {
        using type = std::decay_t<decltype(arg)>;
        if (std::holds_alternative<type>(value)) {
            condition_ << name << bsoncxx::builder::stream::open_document
                       << "$eq" << std::get<type>(value)
                       << bsoncxx::builder::stream::close_document;
        }
    }, value);
    builder_ << "$set" << bsoncxx::builder::stream::open_document;
}

void MongoCommand::set(const std::string& name, const Variant& value) {
    std::visit([&](auto&& arg) {
        using type = std::decay_t<decltype(arg)>;
        if (std::holds_alternative<type>(value)) {
            builder_ << name << std::get<type>(value);
        }
    }, value);
}

bool MongoCommand::insert() {
    // it does not check a document exists in collection
    // just save new
    auto collection = db_[entity_];
    bsoncxx::document::value document = builder_
            << bsoncxx::builder::stream::finalize;
    try {
        collection.insert_one(std::move(document));
        return true;
    } catch(const mongocxx::bulk_write_exception&) {
        return false;
    }
}

bool MongoCommand::update(const bsoncxx::document::view_or_value& filter) {
    auto collection = db_[entity_];
    builder_ << bsoncxx::builder::stream::close_document;
    bsoncxx::document::value document = builder_
            << bsoncxx::builder::stream::finalize;
    try {
        collection.update_one(filter.view(), std::move(document));
        return true;
    } catch(const mongocxx::bulk_write_exception&) {
        return false;
    }
}

bool MongoCommand::execute() {
    bsoncxx::document::value filter = condition_
            << bsoncxx::builder::stream::finalize;
    if (filter.view().empty()) {
        return insert();
    } else {
        return update(filter.view());
    }
}

}  // namespace model::db
