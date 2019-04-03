#ifndef MODEL_DB_COMMAND_H
#define MODEL_DB_COMMAND_H

namespace model {
class BaseField;
}  // namespace model

namespace model::db {

class Command {
public:
    virtual void set(const BaseField* field) = 0;
    virtual void execute() = 0;
    virtual ~Command() = default;
};

}  // namespace model::db

#endif // MODEL_DB_COMMAND_H
