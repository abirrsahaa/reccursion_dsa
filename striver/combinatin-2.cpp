#include <bits/stdc++.h>
using namespace std;

// need to return all possible combination of elements which equals to the target sum
// and the elements can be repeated

// always focus on a singe problem rest reccursiuon will take care of the rest
void helper(int arr[], int index, int target, vector<int> &temp, vector<vector<int>> &ans, int size, int sum)
{
    cout << "the temp array is -->" << endl;
    for (auto i : temp)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "the ans array is -->" << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << " and the respective sum is --> " << sum << endl;
    cout << "and target reached --> " << sum;
    cout << endl;
    // base case
    if (index >= size || sum > target)
    {
        if (sum == target)
        {
            cout << "target reached" << endl;
            ans.push_back(temp);
        }
        return;
    }
    if (sum == target)
    {
        cout << "target reached" << endl;
        ans.push_back(temp);
        return;
    }

    // one case
    // including wala case
    temp.push_back(arr[index]);
    sum += arr[index];
    helper(arr, index + 1, target, temp, ans, size, sum);
    temp.pop_back();
    sum -= arr[index];
    helper(arr, index + 1, target, temp, ans, size, sum);
}

int main()
{
    int arr[] = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    int size = 7;
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