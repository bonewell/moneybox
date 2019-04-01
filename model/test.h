#ifndef TEST_H
#define TEST_H

#include <any>
#include <iostream>
//#include <initializer_list>
#include <map>
#include <string>
#include <tuple>
#include <vector>

//template<typename Tuple, std::size_t... Is>
//void print_impl(const Tuple& names, const Tuple& values, std::index_sequence<Is...>) {
//    ((std::cout << " / " << std::get<Is>(names) << "=" << std::get<Is>(values)), ...);
//}

//template <typename... Types, typename... Args>
//void print(const std::tuple<Types...>& names, const std::tuple<Args...>& values) {
//    print_impl(names, values, std::index_sequence_for<Args...>{});
//}

//template<typename... Args>
//struct Test {
////    std::initializer_list<std::string> names;
//    using Types = std::tuple<Args...>;
//    using Values = std::tuple<Args...>;
//    explicit Test(Args... args) : args{args...} {}
//    Values args;
//    void save() {
//        print(args, args);
//    }
//};

//struct UTest : public Test<int, std::string, long long> {

//};

//using UTest = Test<int, std::string, long long>;


//template<typename... Types>
//class Table {
//protected:
//    using Fields = std::map<std::string, std::any>;
//    explicit Table(const Fields& fields) : fields_{std::move(fields)} {}
//private:
//    Fields fields_;
//};

//using Person = Table<int, std::string, long long>;
//class User : public Person {
//public:
//    Person() : Person({
//                      {"id",
//                   }) {}
//};

//struct Meta {
//    std::string name;
////    virtual auto type() const -> decltype(auto) = 0;
////    virtual ~Meta() = default;
//};

//template<typename T>
//struct MetaCell : public Meta {
//    using type = T;
////    using Meta::Meta;
//    explicit MetaCell(const std::string& name) : Meta{name} {}
////    auto type() const override -> decltype(auto) {
////        std::remove_reference_t<decltype(*this)>()::type v;
////        return *this;
////    }
//};

//class Table {
//public:
//    template<typename T>
//    int registry(const std::string& name) {
//        metas_.emplace(index_, new MetaCell<T>{name});
//        return index_++;
//    }

//    void set(int index, std::any value) {
//        values_.emplace(index, std::move(value));
//    }

//    std::any get(int index) const {
//        return values_.at(index);
//    }

//    void save() {
//        for (auto [i, m]: metas_) {
//            map_in[tin]
//            auto mm = new MetaCell<int>("int");
//            using type = std::remove_pointer_t<decltype(m)>::type;
//            using type = decltype(m->type())::type;
//            type x;
//            std::cout << typeid(x).name() << "\n";
//            using type = std::remove_pointer_t<decltype(m)>();

//            auto v = get(i);
//            auto x = std::any_cast<type>(v);
//            std::cout << m->name << ": " << x << "\n";
//        }
//    }
//protected:
////    int index_{0};
////    std::tuple<Args...> args_;
////    std::map<int, const Meta*> metas_;
//    std::map<int, std::any> values_;
//};

//template <typename... Args>
//class ATable : public Table {
//public:
//    using Meta = std::tuple<Args...>;
//    void save() {
////        for (auto i = 0; i < std::tuple_size<Meta>::value; ++i) {
////            const auto index = i;
////        }
////        auto x = std::get<i>(args_);
//        for (const auto [i, v]: values_) {
//            auto vv = std::any_cast<int>(v);
//            std::cout << ": " << vv << "\n";
//        }
//    }
//private:
//    Meta args_;
//};

//template<typename T>
//class Value {
//public:
//    using type = T;
//    explicit Value(std::string name, Table* table)
//        : table_{table} {
////        index_ = table_->registry<type>(name);
//    }
//    Value& operator=(type value) {
//        table_->set(index_, std::move(value));
//        return *this;
//    }
//    operator type() {
//        return std::any_cast<type>(table_->get(index_));
//    }
//private:
//    int index_;
//    Table* table_;
//};

//class Person : public Table {
//public:
//    Value<int> id{"id", this};
////    Value<std::string> name{"name", this};
////    Value<long long> amount{"amount", this};
//};

//struct Integer : MetaCell<long long> {
//    using MetaCell::MetaCell;
//    Integer& operator=(MetaCell::type value) {
//        value_ = value;
//        return *this;
//    }
//    operator MetaCell::type() {
//        return std::any_cast<MetaCell::type>(value_);
//    }

//private:
//    std::any value_;
//};

//struct Text : MetaCell<std::string> {
//    using MetaCell::MetaCell;
//    Text& operator=(MetaCell::type value) {
//        value_ = value;
//        return *this;
//    }
//    operator MetaCell::type() {
//        return std::any_cast<MetaCell::type>(value_);
//    }

//private:
//    std::any value_;
//};

//struct User {
//    Integer id{"id"};
//    Text name{"name"};
//    Integer amount{"amount"};
//};

//static MetaCell<int> mc{"name"};
/*
class User {
    static MetaCell<int>{"id"};
    static MetaCell<std::stirng}{"name"};
    static MetaCell<long long>{"amount"};
};

class Row {
public:
    void save() {
        for (auto& [n, v]: cells_) {
            std::cout << n << ": " << std::any_cast<T>(v) "\n";
        }
    }
    template<typename T>
    void set(Cell& c) {
        cells_.emplace(c.name, c);
    }
private:
    std::map<std::string, Cell> cells_;
};



template<typename T>
class Field;

class NewTable {
public:
    NewTable() {

    }
    void save() {
        for (auto& [k, v] : fields_) {
//            typename decltype(v)::type f;
//            std::cout << k << ": " << std::any_cast<typename decltype(v)::type>(v) << "\n";
        }
    }
    template<typename T>
    void set(int i, Field<T>& value) {
        fields_.emplace(i, std::any(value));
    }
private:
    std::map<int, std::any> fields_;
};

template<typename T>
class Field {
public:
    using type = T;
    explicit Field(std::string name, NewTable* table) : name_{name}, table_{table} {}
    Field& operator=(type value) {
        table_->set(name_, *this);
        value_ = value;
        return *this;
    }

private:
    std::string name_;
    NewTable* table_;
    type value_{};
};

class User : public NewTable {
public:
    Field<int> id{"id", this};
    Field<std::string> name{"name", this};
    Field<long long> amount{"amount", this};
};
*/

class BaseField;

template <typename... Args>
class Item {
public:
    Item(Args... args) : db_{args} {}
    void registry(BaseField* field) {
        fields_.push_back(field);
    }

    void save();
    void load(const std::string& name);

private:
    std::vector<BaseField*> fields_;
    std::tuple<Args...> db_;
};


class BaseField {
public:
    explicit BaseField(const std::string& name) : name{name} {}
    std::string name;
    template<typename T>
    void save(const T& value) {
        value_ = value;
    }
    template<typename T>
    void load(T& value) {
        value = std::any_cast<T>(value_);
    }
private:
    std::any value_;
};

template <typename T>
class Field : BaseField {
public:
    using type = T;
    Field(const std::string& name, Item* table)
        : BaseField{name}, table_{table} {
        table_->registry(this);
    }

    Field& operator=(const type& value) {
        save(value);
        return *this;
    }

    operator type() {
        type value;
        load(value);
        return value;
    }
private:
    Item* table_;
};

void Item::save() {
    for (auto f: fields_) {
        std::cout << f->name << ": " << f << "\n";
    }
}

void Item::load(const std::string& name) {
//    std::cin >> fields_[]
}

class Person : public Item {
public:
    Field<int> id{"id", this};
    Field<std::string> name{"name", this};
    DataBase<int, std::string> db{id, name};
};

#endif // TEST_H
