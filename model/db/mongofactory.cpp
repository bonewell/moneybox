#include "mongofactory.h"

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/pool.hpp>

#include "mongocommand.h"
#include "mongoquery.h"

namespace model::db {

namespace {
static mongocxx::instance instance;
static mongocxx::database db() {
    static mongocxx::pool pool{mongocxx::uri{}};
    return pool.acquire()->database("moneybox");
}
}  // namespace

Factory& MongoFactory::instance() {
    static MongoFactory factory;
    return factory;
}

QueryPtr MongoFactory::query() {
    return std::make_unique<MongoQuery>(db());
}

CommandPtr MongoFactory::command() {
    return std::make_unique<MongoCommand>(db());
}

}  // namespace model::db
