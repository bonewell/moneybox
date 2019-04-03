#include "table.h"

#include "db/command.h"
#include "db/factory.h"
#include "db/query.h"
#include "field.h"

#include <iostream>
#include <variant>

#include "db/mongofactory.h"

namespace model {

db::Factory& Table::factory_ = db::MongoFactory::instance();

void Table::registry(BaseField* field) {
    fields_.push_back(field);
}

void Table::save() {
    auto command = factory_.command();
    for (const auto* f: fields_) {
        command->set(f->name(), f->value());
    }
    command->execute();
}

void Table::fetch(const BaseField& condition) {
    auto query = factory_.query();
    query->where(condition.name(), condition.value());
    for (auto* f: fields_) {
        query->get(f->name(), f->value());
    }
    query->execute();
}

}  // namespace model
