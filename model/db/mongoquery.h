#ifndef MODEL_DB_MONGOQUERY_H
#define MODEL_DB_MONGOQUERY_H

#include "query.h"

namespace model::db {

class MongoQuery : public Query {
public:
    using Query::Query;
    void entity(const std::string& name) override;
    void where(const std::string& name, const Variant& condition) override;
    void get(const std::string& name, Variant& value) override;
    void execute() override;
};

}  // namespace model::db

#endif // MODEL_DB_MONGOQUERY_H
