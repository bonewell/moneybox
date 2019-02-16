#include <iostream>
#include <gsl/gsl>
#include <boost/asio.hpp>

using namespace std;


void get(gsl::owner<int*> x) {
    *x = 4;
}

int main()
{
    cout << "Hello World!" << endl;
    get(new int{});

    return 0;
}
