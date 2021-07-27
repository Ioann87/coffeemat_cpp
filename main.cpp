#include <coffeemat.h>
#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));

    Coffeemat obj;
    obj.init_coffeemat();
    obj.start();

    return 0;
}
