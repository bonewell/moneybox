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

bool Entity::save() {
    auto command = factory_->command();
    command->entity(name_);
    if (fetched_) {
        auto first = fields_[0];
        command->where(first->name(), first->value());
    }
    for (const auto& f: fields_) {
        command->set(f->name(), f->value());
    }
    return command->execute();
}

bool Entity::fetch(const BaseField& condition) {
    query_ = factory_->query();
    query_->entity(name_);
    query_->where(condition.name(), condition.value());
    if (!query_->execute()) return false;
    return next();
}

bool Entity::next() {
    if (query_->next()) {
        for (auto& f: fields_) {
            query_->get(f->name(), f->value());
        }
        return fetched_ = true;
    }
    return false;
}

}  // namespace model
