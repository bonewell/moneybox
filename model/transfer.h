#ifndef MODEL_TRANSFER_H
#define MODEL_TRANSFER_H

#include <string>

#include "item.h"

namespace model {

/**
 * @brief The Transfer class
 */
class Transfer : public Item {
public:
    int id{0};
    int sender{0};
    int recipient{0};
    long long amount{0};
    std::string description{};
};
}  // namespace model

#endif // MODEL_TRANSFER_H
