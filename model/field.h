#ifndef MODEL_FIELD_H
#define MODEL_FIELD_H

#include <string>

#include "db/variant.h"

namespace model {

class Entity;

class BaseField {
public:
    BaseField(const std::string& name, Entity* entity);
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
    Entity* entity_;
    db::Variant value_;
};

template<typename T>
class Field : public BaseField {
public:
    using type_value = T;
    Field(const std::string& name, Entity* table)
        : BaseField (name, table) {
        set(type_value{});
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
