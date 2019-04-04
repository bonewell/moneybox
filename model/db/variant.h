#ifndef VARIANT_H
#define VARIANT_H

#include <variant>

namespace model::db {
using Variant = std::variant<int32_t, int64_t, std::string>;
}  // namespace model::db

#endif // VARIANT_H
