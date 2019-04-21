#ifndef MODEL_DB_MONGOQUERY_H
#define MODEL_DB_MONGOQUERY_H

#include <string>

#include <mongocxx/database.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include "query.h"

namespace model::db {

class MongoQuery : public Query {
public:
    explicit MongoQuery(mongocxx::database&& db);
    void entity(const std::string& name) override;
    void where(const std::string& name, const Variant& condition) override;
    void get(const std::string& name, Variant& value) override;
    bool execute() override;
    bool next() override;

private:
    mongocxx::database db_;
    std::string entity_;
    bsoncxx::builder::stream::document condition_;
    mongocxx::cursor cursor_;
    mongocxx::cursor::iterator current_;
    bsoncxx::document::view document_;
};

}  // namespace model::db

#endif // MODEL_DB_MONGOQUERY_H
