#ifndef API_MONEYBOX_H
#define API_MONEYBOX_H

#include "api.h"
#include "controller/factory.h"

namespace api {

class MoneyBox : public Api {
public:
    void execute(Rpc& rpc) const override;

private:
    controller::Factory factory_;
};
}  // namespace api

#endif // API_MONEYBOX_H
