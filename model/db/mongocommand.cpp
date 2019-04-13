#include "mongocommand.h"

#include <mongocxx/exception/bulk_write_exception.hpp>

#include "model/field.h"

namespace model::db {

void MongoCommand::entity(const std::string& name) {
    entity_ = name;
}

void MongoCommand::set(const std::string& name, const Variant& value) {
    std::visit([&](auto&& arg) {
        using type = std::decay_t<decltype(arg)>;
        if (std::holds_alternative<type>(value)) {
            builder_ << name << std::get<type>(value);
        }
    }, value);
}

bool MongoCommand::execute() {
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

}  // namespace model::db
