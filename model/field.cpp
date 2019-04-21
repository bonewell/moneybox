#include "field.h"

#include "entity.h"

namespace model {

BaseField::BaseField(std::string_view name, gsl::not_null<Entity*> entity)
    : name_{name}, entity_{entity} {
    entity_->registry(gsl::make_not_null(this));
}

const std::string& BaseField::name() const {
    return name_;
}

const db::Variant& BaseField::value() const {
    return value_;
}

db::Variant& BaseField::value() {
    return value_;
}

}  // namespace model
