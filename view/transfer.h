#ifndef VIEW_TRANSFER_H
#define VIEW_TRANSFER_H

#include <string>
#include <vector>

#include "view.h"

namespace view {

struct TransferData {
    std::string sender;
    std::string recipient;
    long long amount;
    std::string description;
};

using TransferDataList = std::vector<TransferData>;

struct Transfer : public View {
    TransferDataList transfers;
    json::json render() override;
};

}  // namespace view

#endif // VIEW_TRANSFER_H
