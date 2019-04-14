#include <iostream>

#include "api/moneybox.h"
#include "http/handler.h"
#include "model/user.h"

int main()
{
    model::User recipient;
    recipient.name = "Nate";
    recipient.amount = 999;
    recipient.save();

    model::User user;
    user.name = "Bone";
    user.amount = 777;
    user.save();

    api::MoneyBox box;
    http::Handler h1;
    h1.name("/amount");
    h1.request(R"({"user": "Bone"})");
    box.execute(h1);
    std::cout << h1.response() << "\n";

    http::Handler h2;
    h2.name("/transfer/send");
    h2.request(R"({"user": "Bone",
                   "recipient": "Nate",
                   "amount": 333,
                   "description": "present for you"
                })");
    box.execute(h2);
    std::cout << h2.response() << "\n";

    http::Handler h3;
    h3.name("/transfer/send");
    h3.request(R"({"user": "Nate",
                   "recipient": "Bone",
                   "amount": 555,
                   "description": "take back"
                })");
    box.execute(h3);
    std::cout << h3.response() << "\n";

    http::Handler h4;
    h4.name("/transfer");
    h4.request(R"({"user": "Bone"})");
    box.execute(h4);
    std::cout << h4.response() << "\n";

    return 0;
}
