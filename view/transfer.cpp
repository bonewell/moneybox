#include "transfer.h"

namespace view {

json::json Transfer::render() {
    auto array = json::json::array();
    std::for_each(std::begin(transfers), std::end(transfers), [&array](const auto& item) {
        array.push_back({{"id", item.id},
                         {"sender", item.sender},
                         {"recipient", item.recipient},
                         {"amount", item.amount},
                         {"description", item.description}});
    });
    return array;
}

}  // namespace view
