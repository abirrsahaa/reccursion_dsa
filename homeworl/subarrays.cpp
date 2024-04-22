// first design the algorithm '
// given an array need to find all the subarrays of the array
// it is simple in a vector i will be storing the subarrays
// and the index  will be moving until it reaches the end of the array
// if it reaches the end of the array now i will be storing the ans
// tugtyftyft
#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> abir, int size, int index, vector<int> temp, vector<vector<int>> &ans)
{
    // base case
    if (index >= size)
    {
        ans.push_back(temp);
        return;
    }
    // else index is within the range

    // ignore
    helper(abir, size, index + 1, temp, ans);

    // taken
    temp.push_back(abir[index]);
    helper(abir, size, index + 1, temp, ans);
    temp.pop_back();
    // return;
}
int main()
{
    vector<int> abir = {1, 2, 3, 4, 5};
    int size = abir.size();
    // i will need two vector
    vector<int> temp;
    vector<vector<int>> ans;

    helper(abir, size, 0, temp, ans);

    cout << "the subarrays are -> " << endl;

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}