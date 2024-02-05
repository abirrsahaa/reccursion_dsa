#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> &abir, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i * i == n)
            abir.push_back(n);
    }
}
void getting(vector<int> abir, int n, int sum, int &ans, vector<int> &temp)
{
    // base case
    if (sum >= n)
    {
        if (sum == n && temp.size() < ans)
            ans = temp.size();
        return;
    }

    // one case
    for (int i = 0; i < abir.size(); i++)
    {
        // cases
        sum += abir[i];
        temp.push_back(abir[i]);
        getting(abir, n, sum, ans, temp);
        temp.pop_back();
        sum -= abir[i];
    }

    // reccursion will handle
    return;
}
int main()
{
    // first i will find all the perfect squares in that range and store them in a vector
    // then my algo would consist of reccursion which would find the mininum combination to find the sum according to that
    int n = 13;
    vector<int> abir;
    for (int i = 1; i <= n; i++)
    {
        helper(abir, i);
    }
    cout << "the perfect squares in the range is --> " << endl;
    for (auto i : abir)
    {
        cout << i << " ";
    }
    // dekh bhai abhi mereko perfect squares mil gaye hai
    // now apply reccursion to find the combination
    vector<int> temp;
    int ans;
    getting(abir, n, 0, ans, temp);
    cout << "the ans is " << ans << endl;
}