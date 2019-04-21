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
    void where(const std::string& name, const Variant& condition) override;
    void set(const std::string& name, const Variant& value) override;
    bool execute() override;

private:
    bool insert();
    bool update(const bsoncxx::document::view_or_value& filter);
    mongocxx::database db_;
    std::string entity_;
    bsoncxx::builder::stream::document builder_;
    bsoncxx::builder::stream::document condition_;
};

}  // namespace model::db

#endif // MODEL_DB_MONGOCOMMAND_H
