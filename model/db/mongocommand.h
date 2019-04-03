#ifndef MODEL_DB_MONGOCOMMAND_H
#define MODEL_DB_MONGOCOMMAND_H

#include "command.h"

namespace model::db {

class MongoCommand : public Command {
public:
    MongoCommand();
    void set(const BaseField* field) override;
    void execute() override;
};

}  // namespace model::db

#endif // MODEL_DB_MONGOCOMMAND_H
