#include <iostream>

#include <boost/asio.hpp>
#include <gsl/gsl>
#include <nlohmann/json.hpp>

#include "api/moneybox.h"
#include "api/rpc.h"

#include "controller/factory.h"
#include "controller/controller.h"
#include "model/user.h"

using namespace std;

void get(gsl::owner<int*> x) {
    *x = 4;
}

int main()
{
    cout << "Hello World!" << endl;
    get(new int{});

    model::User recipient;
    recipient.name = "Nate";
    recipient.amount = 999;
    recipient.save();

    model::User user;
    user.name = "Bone";
    user.amount = 777;
    user.save();

    api::MoneyBox box;
    controller::Factory factory;
    auto amount = factory.create("/amount");
    auto res_a = amount->execute({{"user", "Bone"}});
    std::cout << res_a << "\n";

    auto transfer_send = factory.create("/transfer/send");
    auto res_ts = transfer_send->execute({
        {"user", "Bone"},
        {"recipient", "Nate"},
        {"amount", 333},
        {"description", "present for you"}
    });
    std::cout << res_ts << "\n";

    auto transfer_send2 = factory.create("/transfer/send");
    auto res_ts2 = transfer_send2->execute({
        {"user", "Nate"},
        {"recipient", "Bone"},
        {"amount", 555},
        {"description", "take back"}
    });
    std::cout << res_ts2 << "\n";

    auto transfer = factory.create("/transfer");
    auto res = transfer->execute({{"user", "Bone"}});
    std::cout << res << "\n";

    return 0;
}
