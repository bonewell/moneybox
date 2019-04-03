#include "mongoquery.h"

namespace model::db {

MongoQuery::MongoQuery() {

}

void MongoQuery::where(const std::string& name, const Variant& value) {

}

void MongoQuery::get(const std::string& name, Variant& value) {
//    std::visit([f](auto&& arg) {
//        using type = std::decay_t<decltype (arg)>;
//        if (std::holds_alternative<type>(f->value())) {
////                f->set<type>();
//        }
//    }, f->value());
}

void MongoQuery::execute() {

}

}  // namespace model::db
