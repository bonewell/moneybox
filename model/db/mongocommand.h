#ifndef MODEL_DB_MONGOCOMMAND_H
#define MODEL_DB_MONGOCOMMAND_H

#include "command.h"

namespace model::db {

class MongoCommand : public Command {
public:
    MongoCommand();
    void set(const std::string& name, const Variant& value) override;
    void execute() override;
};

}  // namespace model::db

#endif // MODEL_DB_MONGOCOMMAND_H
