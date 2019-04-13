#include "transfer.h"

#include "model/user.h"
#include "model/transfer.h"

namespace controller {

json::json Transfer::execute(const json::json &input) {
    model::User user;
    if (user.fetch(user.name = input["user"])) {
        outcoming(user);
        incoming(user);
    }
    return view_.render();
}

void Transfer::outcoming(const model::User& user) {
    model::Transfer transfer;
    if (transfer.fetch(transfer.sender = user.name)) {
        append(transfer);
        while (transfer.next()) {
            append(transfer);
        }
    };
}

void Transfer::incoming(const model::User& user) {
    model::Transfer transfer;
    if (transfer.fetch(transfer.recipient = user.name)) {
        append(transfer);
        while (transfer.next()) {
            append(transfer);
        }
    };
}

void Transfer::append(const model::Transfer& transfer) {
    view_.transfers.push_back({transfer.sender,
                              transfer.recipient,
                              transfer.amount,
                              transfer.description});
}

}  // namespace controller
