#ifndef MODEL_DB_COMMAND_H
#define MODEL_DB_COMMAND_H

namespace model::db {

class Command {
public:
    virtual void set() = 0;
    virtual void execute() = 0;
    virtual ~Command() = default;
};

}  // namespace model::db

#endif // MODEL_DB_COMMAND_H
