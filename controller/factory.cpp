#include "factory.h"

#include "amount.h"
#include "transfer.h"
#include "transfersend.h"

namespace controller {

ControllerPtr Factory::create(std::string_view name) const {
    if (name == "/amount") return std::make_unique<Amount>();
    if (name == "/transfer") return std::make_unique<Transfer>();
    if (name == "/transfer/send") return std::make_unique<TransferSend>();
    return {};
}

}  // namespace controller
