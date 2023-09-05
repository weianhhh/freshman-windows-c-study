#include <iostream>
using namespace std;

int mian()
{
    int x1 = 1, x2 = x1, x3 = x2;

    x1 <<= 1; //x *= 2;
    x2 >>= 1; //x /= 2;
    x3 = (x3 << 1) + (x3 << 3);//x *= 10;
    cout << x1 << x2 << x3 << "\n" << endl;
    return 0;
}