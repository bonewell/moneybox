#include "item.h"

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/view_or_value.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/pool.hpp>

#include <iostream>

namespace model {

void Item::save()
{
    mongocxx::pool pool{mongocxx::uri{}};

    auto client = pool.acquire();
    auto db = client->database("moneybox");
    auto collection = db["main"];

    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
            << "id" << id
            << "amount" << amount
            << "desc" << desc
            << bsoncxx::builder::stream::finalize;

    auto res = collection.insert_one(std::move(doc_value));
}

void Item::fetch(int id) {
    mongocxx::pool pool{mongocxx::uri{}};

    auto client = pool.acquire();
    auto db = client->database("moneybox");
    auto collection = db["main"];

    bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result =
            collection.find_one(bsoncxx::builder::stream::document{} << "id" << id << bsoncxx::builder::stream::finalize);
    if (maybe_result) {
        auto view = maybe_result->view();
        this->id = view["id"].get_int32();
        this->amount = view["amount"].get_int64();
        this->desc = view["desc"].get_utf8().value.to_string();
    }
}

}  // namespace model
