#ifndef MODEL_DB_MONGOCOMMAND_H
#define MODEL_DB_MONGOCOMMAND_H

#include <string>

#include <mongocxx/database.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include "command.h"

namespace model::db {

class MongoCommand : public Command {
public:
    explicit MongoCommand(mongocxx::database&& db) : db_{std::move(db)} {}
    void entity(const std::string& name) override;
    void set(const std::string& name, const Variant& value) override;
    bool execute() override;

private:
    mongocxx::database db_;
    std::string entity_;
    bsoncxx::builder::stream::document builder_;
};

}  // namespace model::db

#endif // MODEL_DB_MONGOCOMMAND_H
