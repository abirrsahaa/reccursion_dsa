#include <bits/stdc++.h>
using namespace std;

// need to return all possible combination of elements which equals to the target sum
// and the elements can be repeated

// always focus on a singe problem rest reccursiuon will take care of the rest
void helper(int arr[], int index, int target, vector<int> &temp, vector<vector<int>> &ans, int size, int sum)
{
    cout << "inside helper function" << endl;
    // base case
    if (index >= size || sum > target)
    {
        return;
    }
    if (sum == target)
    {
        ans.push_back(temp);
        return;
    }

    // one case
    // including wala case
    temp.push_back(arr[index]);
    sum += arr[index];
    helper(arr, index, target, temp, ans, size, sum);
    temp.pop_back();
    sum -= arr[index];
    helper(arr, index + 1, target, temp, ans, size, sum);
}

int main()
{
    int arr[] = {2, 3, 6, 7};
    int target = 7;
    int size = 4;
    int sum = 0;
    vector<int> temp;
    vector<vector<int>> ans;
    helper(arr, 0, target, temp, ans, size, sum);

    cout << "printing all possible combinations of the resulting sum is --> " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}