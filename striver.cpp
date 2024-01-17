// print N to 1 using backtrack !!

#include <iostream>
using namespace std;
void func(int n, int i)
{
    // base case
    if (i >= n)
    {
        return;
    }
    // else case
    i++;
    func(n, i);

    cout << i << endl;
}
int main()
{
    int n;
    cin >> n;
    func(n, 0);
}