#include "mongoquery.h"

namespace model::db {

MongoQuery::MongoQuery() {

}

void MongoQuery::where(const BaseField* condition) {

}

void MongoQuery::get(BaseField* field) {
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
