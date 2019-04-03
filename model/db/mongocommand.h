#ifndef MODEL_DB_MONGOCOMMAND_H
#define MODEL_DB_MONGOCOMMAND_H

#include "command.h"

namespace model::db {

class MongoCommand : public Command {
public:
    using Command::Command;
    void entity(const std::string& name) override;
    void set(const std::string& name, const Variant& value) override;
    void execute() override;
};

}  // namespace model::db

#endif // MODEL_DB_MONGOCOMMAND_H
