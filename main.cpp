#include "api/moneybox.h"
#include "http/server.h"
#include "model/user.h"

void init_db() {
    for (auto name : {"Nate", "Bone"}) {
        model::User user;
        if (!user.fetch(user.name = name)) {
            user.name = name;
            user.amount = 1000;
            user.save();
        }
    }
}

int main()
{
    init_db();

    api::MoneyBox box;
    http::Server server{box};
    server.run();

    return 0;
}
