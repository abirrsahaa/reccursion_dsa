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