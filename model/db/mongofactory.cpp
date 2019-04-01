#include "mongofactory.h"

namespace model::db {

QueryPtr MongoFactory::query() {
    return QueryPtr{};
}

CommandPtr MongoFactory::command() {
    return CommandPtr{};
}

}
