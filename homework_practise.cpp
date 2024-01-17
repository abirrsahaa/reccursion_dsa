// QUESTION - LEAST NUMBER OF PERFECT SQUARE NUMBER THAT SUM TO N
// LET THE NUMBER BE 12 THEN IT IS 4+4+4

#include <iostream>
#include <algorithm>
#include <limit.h>
#include <cmath>
using namespace std;
int least()
{
    // base case
    if (target < 0)
    {
        return INT_MAX;
    }

    // execution of one case baki toh reccursion dekh lega
    int end = sqrt(target);

    int ans = 0;

    for (int i = 1; i <= end; i++)
    {

        ans =
    }
}
int main()
{
    int n = 12;
}