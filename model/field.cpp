#include "field.h"

#include "entity.h"

namespace model {

BaseField::BaseField(const std::string& name, Entity* entity)
    : name_{name}, entity_{entity} {
    entity_->registry(this);
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
