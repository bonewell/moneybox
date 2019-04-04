#ifndef MODEL_DB_COMMAND_H
#define MODEL_DB_COMMAND_H

#include <string>

#include "variant.h"

namespace model::db {

class Command {
public:
    virtual void entity(const std::string& name) = 0;
    virtual void set(const std::string& name, const Variant& value) = 0;
    virtual void execute() = 0;
    virtual ~Command() = default;
};

}  // namespace model::db

#endif // MODEL_DB_COMMAND_H
