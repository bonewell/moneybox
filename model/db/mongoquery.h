#ifndef MODEL_DB_MONGOQUERY_H
#define MODEL_DB_MONGOQUERY_H

#include "query.h"

namespace model::db {

class MongoQuery : public Query {
public:
    MongoQuery();
    void where(const BaseField* condition) override;
    void get(BaseField* field) override;
    void execute() override;
};

}  // namespace model::db

#endif // MODEL_DB_MONGOQUERY_H
