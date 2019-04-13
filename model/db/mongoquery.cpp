#include "mongoquery.h"

#include <mongocxx/exception/logic_error.hpp>
#include <mongocxx/exception/query_exception.hpp>

namespace model::db {

MongoQuery::MongoQuery(mongocxx::database&& db)
    : db_{std::move(db)},
      cursor_{db_["stub"].find({})},
      current_{cursor_.begin()} {}

void MongoQuery::entity(const std::string &name) {
    entity_ = name;
}

void MongoQuery::where(const std::string& name, const Variant& value) {
    std::visit([&](auto&& arg) {
        using type = std::decay_t<decltype(arg)>;
        if (std::holds_alternative<type>(value)) {
            condition_ << name << bsoncxx::builder::stream::open_document
                       << "$eq" << std::get<type>(value)
                       << bsoncxx::builder::stream::close_document;
        }
    }, value);
}

void MongoQuery::get(const std::string& name, Variant& value) {
    auto field = document_[name];
    std::visit([&](auto&& arg) {
        using type = std::decay_t<decltype (arg)>;
        if (std::holds_alternative<type>(value)) {
            if (std::is_same_v<type, int32_t>) {
                value = field.get_int32();
            } else if (std::is_same_v<type, int64_t>) {
                value = field.get_int64();
            } else if (std::is_same_v<type, std::string>) {
                value = field.get_utf8().value.to_string();
            }
        }
    }, value);
}

bool MongoQuery::execute() try {
    auto collection = db_[entity_];
    bsoncxx::document::value doc = condition_ << bsoncxx::builder::stream::finalize;
    cursor_ = collection.find(doc.view());
    current_ = cursor_.begin();
    return true;
} catch(const mongocxx::logic_error&) {
    return false;
}

bool MongoQuery::next() try {
    document_ = *current_;
    auto has = current_ != cursor_.end();
    ++current_;
    return has;
} catch(const mongocxx::query_exception&) {
    return false;
}

}  // namespace model::db
