#include <iostream>

#include <boost/asio.hpp>
#include <gsl/gsl>

//#include "model/item.h"
#include "model/user.h"

using namespace std;

void get(gsl::owner<int*> x) {
    *x = 4;
}

int main()
{
    cout << "Hello World!" << endl;
    get(new int{});

//    model::Item i;
//    i.id = 3;
//    i.amount = 333;
//    i.desc = "thre";
//    i.save();

//    model::Item o;
//    o.fetch(3);
//    std::cout << o.id << "-" << o.amount << "-" << o.desc << "\n";

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
