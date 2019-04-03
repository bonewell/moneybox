#include "mongoquery.h"

namespace model::db {

void MongoQuery::entity(const std::string &name) {

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

bool MongoQuery::execute() {
//    mongocxx::pool pool{mongocxx::uri{}};

//    auto client = pool.acquire();
//    auto db = client->database("moneybox");
//    auto collection = db["main"];

//    bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result =
//            collection.find_one(bsoncxx::builder::stream::document{} << "id" << id << bsoncxx::builder::stream::finalize);
//    if (maybe_result) {
//        auto view = maybe_result->view();
//        this->id = view["id"].get_int32();
//        this->amount = view["amount"].get_int64();
//        this->desc = view["desc"].get_utf8().value.to_string();
//    }
//        std::get_if<T>(&f->value());
    return false;
}

}  // namespace model::db
