#ifndef MODEL_DB_MONGOQUERY_H
#define MODEL_DB_MONGOQUERY_H

#include <mongocxx/database.hpp>

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
};

}  // namespace model::db

#endif // MODEL_DB_MONGOQUERY_H
