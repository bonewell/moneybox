#ifndef MODEL_FIELD_H
#define MODEL_FIELD_H

#include <string>
#include <variant>

namespace model {

using Variant = std::variant<int, long long, std::string>;

class Table;

class BaseField {
public:
    BaseField(const std::string& name, Table* table);
    virtual ~BaseField() = default;
    const std::string& name() const;
    const Variant& value() const;

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
    Table* table_;
    Variant value_;
};

template<typename T>
class Field : public BaseField {
public:
    using type_value = T;
    Field(const std::string& name, Table* table)
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
};

using Integer = Field<int>;
using LongLong = Field<long long>;
using Text = Field<std::string>;

}  // namespace model

#endif // MODEL_FIELD_H
