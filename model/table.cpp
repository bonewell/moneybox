#include "table.h"

#include "field.h"

#include <iostream>
#include <variant>

namespace model {

void Table::registry(BaseField* field) {
    fields_.push_back(field);
}

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

}  // namespace model
