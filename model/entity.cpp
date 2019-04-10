#include "entity.h"

#include "db/command.h"
#include "db/factory.h"
#include "db/mongofactory.h"
#include "db/query.h"
#include "field.h"

namespace model {

gsl::not_null<db::Factory*> Entity::factory_ = gsl::make_not_null(&db::MongoFactory::instance());

void Entity::registry(gsl::not_null<BaseField*> field) {
    fields_.push_back(field);
}

void Entity::save() {
    auto command = factory_->command();
    command->entity(name_);
    for (const auto& f: fields_) {
        command->set(f->name(), f->value());
    }
    command->execute();
}

bool Entity::fetch(const BaseField& condition) {
    auto query = factory_->query();
    query->entity(name_);
    query->where(condition.name(), condition.value());
    if (!query->execute()) return false;
    for (auto& f: fields_) {
        query->get(f->name(), f->value());
    }
    return true;
}

}  // namespace model
