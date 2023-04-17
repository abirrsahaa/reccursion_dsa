// concept--> INCLUSION AND EXCLUSION

// PRINTING THE SUBSEQUENCES-->

#include <iostream>
#include <vector>
using namespace std;

void printSubsequences(string str, int n, string output, int i, vector<string> &v)
{
    // base case
    if (i >= n)
    {
        v.push_back(output);
        return;
    }

    // include
    printSubsequences(str, n, output + str[i], i + 1, v);

    // exclude
    printSubsequences(str, n, output, i + 1, v);
}

int main()
{
    string str = "abcd";
    string output = "";
    vector<string> v;
    int i = 0;
    int n = str.length();
    printSubsequences(str, n, output, i, v);

    cout << "Printing all subsequences " << endl;
    for (auto val : v)
    {
        cout << val << " ";
    }

    cout << endl
         << "Size of vector is: " << v.size() << endl;

    return 0;
}

// concept-->  USING FOR LOOP IN RECCURSION

// minimum elements for sum

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(vector<int> &arr, int target)
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

    // let's solve 1 case
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = solve(arr, target - arr[i]);
        if (ans != INT_MAX)
        {
            // cout<<"the mini is between "<<mini<<" and "<<ans+1<<endl;
            mini = min(mini, ans + 1);
            // cout<<"the mini is --> "<<mini<<endl;
        }
    }

    return mini;
}

int main()
{
    vector<int> arr{1, 2};
    int target = 5;

    int ans = solve(arr, target);
    cout << "Answer is: " << ans << endl;
    return 0;
}

// CONCEPT- THE RECCURSIVE THINKING APPROACH

// MAXIMUM NO TIMES THE ROD CAN BE CUT

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(int n, int x, int y, int z)
{
    // base case
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    // solving for that one single case

    // dont confuse why there is 3 reccursive call
    // as we have to cut the rod with three variables ....

    int ans1 = solve(n - x, x, y, z) + 1;
    int ans2 = solve(n - y, x, y, z) + 1;
    int ans3 = solve(n - z, x, y, z) + 1;

    // processing part ..--->

    int ans = max(ans1, max(ans2, ans3));

    return ans;
}

int main()
{
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    // solve function -> returns maximum number of segments
    int ans = solve(n, x, y, z);
    // ans -> valid && invalid

    if (ans < 0)
        ans = 0;
    cout << "Answer is: " << ans << endl;

    return 0;
}

// CONCEPT-->USING FOR LOOP IN RECCURSION AND TRAVERSING THROUGH THE ARRAY

// try to fucking develop the logic that adjacent sum what it means take a small case and then try to solve it
// reccursion simply means do one case and leave the rest for the reccursion to handle
// so if i need to find the largest sum of non adjacent elements in the array and i take just two of the first elements ..
// just think that if i have taken the first element i really not have to think about the adjacent element at ALL   as it is clear that i dont have to take it
// now what if i dont include the first then its obvious to skip this and move to the next and then repeat the same decision making process

// MAXIMUM SUM OF NON ADJACENT ELEMENT

// #include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void solve(vector<int> &arr, int i, int sum, int &maxi)
{
    // base case
    if (i >= arr.size())
    {
        // maxi update;
        maxi = max(sum, maxi);
        return;
    }

    // include
    solve(arr, i + 2, sum + arr[i], maxi);
    // exclude
    solve(arr, i + 1, sum, maxi);
}

int main()
{
    vector<int> arr{1, 2, 3, 1, 3, 5, 8, 1, 9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;
    solve(arr, i, sum, maxi);

    cout << maxi << endl;

    return 0;
}

another way to do the above same problem and has the name of house robber

#include <iostream>
#include <vector>
#include <limits.h>
    using namespace std;

int solve(vector<int> &arr, int i)
{
    // base case
    if (i >= arr.size())
    {
        // maxi update;
        //  maxi = max(sum, maxi);
        return 0;
    }

    // include
    int ans = arr[i] + solve(arr, i + 2);
    // solve(arr,i+2,sum+arr[i] ,maxi );
    // exclude
    int ans1 = 0 + solve(arr, i + 1);

    return max(ans, ans1);
}

int main()
{
    vector<int> arr{1, 2, 3, 1, 3, 5, 8, 1, 9};
    // int sum = 0;
    // int maxi = INT_MIN;
    int i = 0;
    int maxi = solve(arr, i);

    cout << maxi << endl;

    return 0;
}

// concept of backtracking/

// every other question i have a bit of understanding but this question below i havent been
// able to figure out till now what should i be doing!

// finding the permutations of a string

#include <iostream>
using namespace std;
void printPermutation(string &str, int i)
{
    // base case
    if (i >= str.length())
    {
        cout << str << " ";
        return;
    }

    // swapping
    for (int j = i; j < str.length(); j++)
    {
        // swap
        swap(str[i], str[j]);
        // rec call
        printPermutation(str, i + 1);
        // backtracking - to recreate the original input string
        swap(str[i], str[j]);
    }
}
int main()
{
    string str = "abc";
    int i = 0;
    printPermutation(str, i);
    return 0;
}
