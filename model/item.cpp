#include "item.h"

#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/pool.hpp>

namespace model {

void Item::save()
{
    mongocxx::instance instance{};
    mongocxx::pool pool{mongocxx::uri{}};

    auto client = pool.acquire();
    auto db = client->database("moneybox");
    auto collection = db["main"];

    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
            << "name" << "Bone" << "amount" << 777
            << bsoncxx::builder::stream::finalize;

    auto res = collection.insert_one(std::move(doc_value));
}

}  // namespace model
