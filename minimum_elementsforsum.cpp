#include <iostream>
#include <limits.h>
using namespace std;
int find_min(int arr[], int n, int target)
{

    // base case
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    // al case kar deta hu baki ka reccursion sambhal lega
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        // int mini=INT_MAX;
        int ans = find_min(arr, n, target - arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
        // return mini;
    }
    return mini;
}
int main()
{

    int arr[2] = {1, 2};
    int target = 3;
    int n = 2;

    cout << "the minimmum number of elements for the sum is -->" << find_min(arr, n, target);
}