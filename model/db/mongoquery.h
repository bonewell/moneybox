#ifndef MODEL_DB_MONGOQUERY_H
#define MODEL_DB_MONGOQUERY_H

#include <string>

#include <mongocxx/database.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include "query.h"

namespace model::db {

class MongoQuery : public Query {
public:
    explicit MongoQuery(mongocxx::database&& db) : db_{std::move(db)} {}
    void entity(const std::string& name) override;
    void where(const std::string& name, const Variant& condition) override;
    void get(const std::string& name, Variant& value) override;
    bool execute() override;
private:
    mongocxx::database db_;
    std::string entity_;
    bsoncxx::builder::stream::document condition_;
    bsoncxx::stdx::optional<bsoncxx::document::value> result_;
};

}  // namespace model::db

#endif // MODEL_DB_MONGOQUERY_H
