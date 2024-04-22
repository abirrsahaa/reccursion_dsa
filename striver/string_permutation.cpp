#include <bits/stdc++.h>
using namespace std;
void helper(string arr, int index)
{
    // base case
    if (index == arr.length())
    {
        cout << arr << endl;
        return;
    }

    for (int i = index; i < arr.length(); i++)
    {
        swap(arr[index], arr[i]);
        helper(arr, index + 1);
    }
}
int main()
{
    string abir = "abir";
    helper(abir, 0);
}