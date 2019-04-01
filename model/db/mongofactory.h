#ifndef MODEL_DB_MONGOFACTORY_H
#define MODEL_DB_MONGOFACTORY_H

#include "model/db/factory.h"

namespace model::db {

class MongoFactory : public Factory {
public:
    QueryPtr query() override;
    CommandPtr command() override;
};
}  // namespace mongo::db

#endif // MODEL_DB_MONGOFACTORY_H
