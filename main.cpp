#include <iostream>
#include <string_view>

#include <boost/asio.hpp>
#include <gsl/gsl>

#include "model/user.h"
#include "model/transfer.h"

using namespace std;

void get(gsl::owner<int*> x) {
    *x = 4;
}

int main()
{
    cout << "Hello World!" << endl;
    get(new int{});

    auto s = "sdaf"sv;

    model::User u;
    u.id = 3;
    u.name = "Bone";
    u.amount = 777;
    u.save();

    model::User nu;
    nu.fetch(nu.name = "Bone");
    std::cout << int{nu.id}
              << std::string{nu.name}
              << static_cast<long long>(nu.amount) << "\n";

    return 0;
}
