#include "field.h"

#include "table.h"

namespace model {

BaseField::BaseField(const std::string& name, Table* table)
    : name_{name}, table_{table} {
    table_->registry(this);
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
