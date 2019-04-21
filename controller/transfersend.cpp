#include "transfersend.h"

#include "model/transfer.h"
#include "model/user.h"

namespace controller {

json::json TransferSend::execute(const json::json &input) {
    model::User user;
    auto user_exists = user.fetch(user.name = input["user"]);
    model::User recipient;
    auto recipient_exists = recipient.fetch(recipient.name = input["recipient"]);
    if (user_exists && recipient_exists) {
        model::Transfer transfer;
        transfer.sender = user.name;
        transfer.recipient = recipient.name;
        transfer.amount = input["amount"];
        transfer.description = input["description"];
        view_.result = transfer.save();
        user.amount = user.amount - transfer.amount;
        recipient.amount = recipient.amount + transfer.amount;
        user.save();
        recipient.save();
    } else {
        view_.result = false;
    }
    return view_.render();
}

}  // namespace controller
