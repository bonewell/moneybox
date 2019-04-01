#include <iostream>

#include <boost/asio.hpp>
#include <gsl/gsl>

//#include "model/test.h"

#include <type_traits>
#include <variant>

#include "model/user.h"

using namespace std;

void get(gsl::owner<int*> x) {
    *x = 4;
}

int main()
{
    cout << "Hello World!" << endl;
    get(new int{});

//    model::User user;
//    user.name = "Bone";
//    user.amount = 777;
//    user.save();


    model::User u;
    u.id = 3;
    u.name = "Bone";
    u.amount = 777;
    u.save();

    int id = u.id;
    std::cout << typeid(id).name() << "\n";

    model::User nu;
    nu.fetch(nu.name = "Natat");

    std::variant<int, long long> v;
    auto x = std::get<0>(v);
    using type = std::decay_t<decltype(x)>;
    type y;
    std::cout << typeid(y).name() << "\n";

    return 0;
}
