#include "mongocommand.h"

#include "model/field.h"

namespace model::db {

void MongoCommand::entity(const std::string &name) {

}

void MongoCommand::set(const std::string& name, const Variant& value) {
//    std::visit([f](auto&& arg) {
//        using type = std::decay_t<decltype(arg)>;
//        if (std::holds_alternative<type>(f->value())) {
//            std::cout << f->name() << ": " << std::get<type>(f->value()) << "\n";
//        }
//    }, f->value());
    //std::get_if<T>(&f->value());
//    field->name();
}

void MongoCommand::execute() {
//    mongocxx::pool pool{mongocxx::uri{}};

//    auto client = pool.acquire();
//    auto db = client->database("moneybox");
//    auto collection = db["main"];

//    auto builder = bsoncxx::builder::stream::document{};
//    bsoncxx::document::value doc_value = builder
//            << "id" << id
//            << "amount" << amount
//            << "desc" << desc
//            << bsoncxx::builder::stream::finalize;

//    auto res = collection.insert_one(std::move(doc_value));
}

}  // namespace model::db
