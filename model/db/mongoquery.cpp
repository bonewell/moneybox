#include "mongoquery.h"

namespace model::db {

void MongoQuery::entity(const std::string &name) {
    entity_ = name;
}

void MongoQuery::where(const std::string& name, const Variant& value) {
    std::visit([&](auto&& arg) {
        using type = std::decay_t<decltype(arg)>;
        if (std::holds_alternative<type>(value)) {
            condition_ << name << std::get<type>(value)
                       << bsoncxx::builder::stream::finalize;
        }
    }, value);
}

void MongoQuery::get(const std::string& name, Variant& value) {
    auto field = result_->view()[name];
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

bool MongoQuery::execute() {
    auto collection = db_[entity_];
    result_ = collection.find_one(condition_.view());
    return bool{result_};
}

}  // namespace model::db
