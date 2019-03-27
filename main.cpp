#include <iostream>

#include <boost/asio.hpp>
#include <gsl/gsl>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

using namespace std;

void get(gsl::owner<int*> x) {
    *x = 4;
}

int main()
{
    mongocxx::instance instance{};
    mongocxx::client client{mongocxx::uri{}};

    cout << "Hello World!" << endl;
    get(new int{});

    return 0;
}
