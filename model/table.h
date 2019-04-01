#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <variant>

using Variant = std::variant<int, long long, std::string>;
class BaseField;

class Table {
public:
    void registry(BaseField* field) {
        fields_.push_back(field);
    }
    void save();
    void fetch(const BaseField& condition);
private:
    std::vector<BaseField*> fields_;
};

class BaseField {
public:
    explicit BaseField(const std::string& name, Table* table)
        : name_{name}, table_{table} {
        table_->registry(this);
    }
    virtual ~BaseField() = default;
    template<typename T>
    void set(const T& value) {
        value_ = value;
    }
    template<typename T>
    const T& get() const {
        return std::get<T>(value_);
    }
    const std::string& name() const {
        return name_;
    }
    const Variant& value() const {
        return value_;
    }
private:
    const std::string name_;
    Table* table_;
    Variant value_;
};

void Table::save() {
    for (const auto* f: fields_) {
        std::visit([f](auto&& arg) {
            using type = std::decay_t<decltype(arg)>;
            if (std::holds_alternative<type>(f->value())) {
                std::cout << f->name() << ": " << std::get<type>(f->value()) << "\n";
            }
        }, f->value());
    }
}

void Table::fetch(const BaseField& condition) {
    struct query {int id;
                  std::string name;
                  long long amount;};
    for (const auto* f: fields_) {
        std::visit([f](auto&& arg) {
            using type = std::decay_t<decltype (arg)>;
            if (std::holds_alternative<type>(f->value())) {
//                f->set<type>();
            }
        }, f->value());
    }
}

template<typename T>
class Field : public BaseField {
public:
    using type_value = T;
    using BaseField::BaseField;
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

class User : public Table {
public:
    Integer id{"id", this};
    Text name{"name", this};
    LongLong amount{"amount", this};
};

#endif // TABLE_H
