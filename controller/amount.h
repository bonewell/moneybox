#ifndef CONTROLLER_AMOUNT_H
#define CONTROLLER_AMOUNT_H

#include "controller.h"
#include "view/amount.h"

namespace controller {

class Amount : public Controller {
public:
    json::json execute(const json::json& input) override;

private:
    view::Amount view_;
};

}  // namespace controller

#endif // CONTROLLER_AMOUNT_H
