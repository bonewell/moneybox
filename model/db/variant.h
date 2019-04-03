#ifndef VARIANT_H
#define VARIANT_H

#include <variant>

namespace model::db {
using Variant = std::variant<int, long long, std::string>;
}  // namespace model::db

#endif // VARIANT_H
