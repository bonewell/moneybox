#include <iostream>

#include <boost/asio.hpp>
#include <gsl/gsl>

#include "model/user.h"

using namespace std;

void get(gsl::owner<int*> x) {
    *x = 4;
}

int main()
{
    cout << "Hello World!" << endl;
    get(new int{});

    model::User user;
    user.name = "Bone";
    user.amount = 777;
    user.save();

    return 0;
}
