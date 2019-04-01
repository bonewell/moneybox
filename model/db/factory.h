#ifndef FACTORY_H
#define FACTORY_H

#include <memory>

#include "model/db/command.h"
#include "model/db/query.h"

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

#endif // FACTORY_H
