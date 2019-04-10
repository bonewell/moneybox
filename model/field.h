#ifndef MODEL_FIELD_H
#define MODEL_FIELD_H

#include <string>
#include <string_view>

#include <gsl/gsl>

#include "db/variant.h"

namespace model {

class Entity;

class BaseField {
public:
    BaseField(std::string_view name, gsl::not_null<Entity*> entity);
    virtual ~BaseField() = default;
    const std::string& name() const;
    const db::Variant& value() const;
    db::Variant& value();

protected:
    template<typename T>
    void set(const T& value) {
        value_ = value;
    }
    template<typename T>
    const T& get() const {
        return std::get<T>(value_);
    }

private:
    const std::string name_;
    gsl::not_null<Entity*> entity_;
    db::Variant value_;
};

template<typename T>
class Field : public BaseField {
public:
    using type_value = T;
    Field(std::string_view name, Entity* table)
        : BaseField (name, gsl::make_not_null(table)) {
        set(type_value{});  // to keep type
    }
    Field& operator=(type_value value) {
        set(value);
        return *this;
    }
    operator type_value() const {
        return get<type_value>();
    }
private:
    using BaseField::name;
    using BaseField::value;
};

using Integer = Field<int32_t>;
using LongLong = Field<int64_t>;
using Text = Field<std::string>;

}  // namespace model

#endif // MODEL_FIELD_H
