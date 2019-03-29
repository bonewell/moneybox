#ifndef MODEL_USER_H
#define MODEL_USER_H

#include <vector>
#include <string>

#include "item.h"

namespace model {

using TransferList = std::vector<int>;

/**
 * @brief The User class
 */
class User : public Item {
public:
    int id{0};
    std::string name{};
    long long amount{0};
    TransferList transfers{};
};
}  // namespace model

#endif // MODEL_USER_H
