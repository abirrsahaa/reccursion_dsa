#include <iostream>
#include <limits.h>
using namespace std;
int max_time(int x, int y, int z, int rod)
{
    // base case
    if (rod == 0)
    {
        return 0;
    }
    if (rod < 0)
    {
        return INT_MIN;
    }

    // solve for one case and recursion will take care of the rest

    // for x
}
int main()
{

    int rod = 5;
    int x = 2;
    int y = 5;
    int z = 2;

    // cout<<"the maximum number of times is --> "<<max_time(x,y,z,rod);
    if (max_time(x, y, z, rod) == INT_MAX)
    {
        cout << 0;
    }
    else
    {
    }
}