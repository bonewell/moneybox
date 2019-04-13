#ifndef CONTROLLER_TRANSFERSEND_H
#define CONTROLLER_TRANSFERSEND_H

#include "controller.h"
#include "view/transfersend.h"

namespace controller {

class TransferSend : public Controller {
public:
    json::json execute(const json::json& input) override;

private:
    view::TransferSend view;
};

}  // namespace controller

#endif // CONTROLLER_TRANSFERSEND_H
