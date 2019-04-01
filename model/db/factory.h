#ifndef MODEL_DB_FACTORY_H
#define MODEL_DB_FACTORY_H

#include <memory>

#include "command.h"
#include "query.h"

namespace model::db {

using QueryPtr = std::unique_ptr<Query>;
using CommandPtr = std::unique_ptr<Command>;

class Factory
{
public:
    virtual QueryPtr query() = 0;
    virtual CommandPtr command() = 0;
    virtual ~Factory() = default;
};

}  // namespace model::db

#endif // MODEL_DB_FACTORY_H
