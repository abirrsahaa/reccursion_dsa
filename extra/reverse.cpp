#include <bits/stdc++.h>
using namespace std;
void reverse(string abir, int index, string &ans)
{
    // base case
    if (index == abir.length())
    {
        return;
    }
    reverse(abir, index + 1, ans);
    ans += abir[index];
}
int main()
{
    string abir = "abir";
    string ans = "";
    reverse(abir, 0, ans);
    cout << ans << endl;
}