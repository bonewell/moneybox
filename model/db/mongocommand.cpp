#include "mongocommand.h"

#include "model/field.h"

namespace model::db {

MongoCommand::MongoCommand() {

}

void MongoCommand::set(const std::string& name, const Variant& value) {
//    std::visit([f](auto&& arg) {
//        using type = std::decay_t<decltype(arg)>;
//        if (std::holds_alternative<type>(f->value())) {
//            std::cout << f->name() << ": " << std::get<type>(f->value()) << "\n";
//        }
//    }, f->value());
    //std::get_if<T>(&f->value());
//    field->name();
}

void MongoCommand::execute() {

}

}  // namespace model::db
