#ifndef CONTROLLER_TRANSFER_H
#define CONTROLLER_TRANSFER_H

#include "controller.h"
#include "view/transfer.h"

namespace model {
class Transfer;
class User;
}  // namespace model

namespace controller {

class Transfer : public Controller {
public:
    json::json execute(const json::json& input) override;

private:
    void outcoming(const model::User& user);
    void incoming(const model::User& user);
    void append(const model::Transfer& transfer);
    view::Transfer view_;
};

}  // namespace controller

#endif // CONTROLLER_TRANSFER_H
