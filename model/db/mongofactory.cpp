#include "mongofactory.h"

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/pool.hpp>

#include "mongocommand.h"
#include "mongoquery.h"

namespace model::db {

namespace {
static mongocxx::instance instance;
static mongocxx::collection GetCollection() {
    static mongocxx::pool pool{mongocxx::uri{}};
    auto db = pool.acquire()->database("moneybox");
    return db["main"];
}
}  // namespace

Factory& GetFactory() {
    static MongoFactory factory{};
    return factory;
}

QueryPtr MongoFactory::query() {
    auto collection = GetCollection();
    return std::make_unique<MongoQuery>();
}

CommandPtr MongoFactory::command() {
    auto collection = GetCollection();
    return std::make_unique<MongoCommand>();
}

}  // namespace model::db
