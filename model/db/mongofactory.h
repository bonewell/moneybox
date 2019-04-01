#ifndef MONGOFACTORY_H
#define MONGOFACTORY_H

#include "model/db/factory.h"

namespace model::db {

class MongoFactory : public Factory {
public:
    QueryPtr query() override;
    CommandPtr command() override;
};
}  // namespace mongo::db

#endif // MONGOFACTORY_H
