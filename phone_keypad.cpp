#include <iostream>
#include <vector>
using namespace std;

void get(string input, vector<string> &output, vector<string> f, int index, string &getting)
{
    // base case
    if (index >= input.length())
    {
        output.push_back(getting);
        return;
    }

    // ak case solve kar deta hu
    // amar oi specific number er liga ..joto letter possible ato da include korte lagbo ....
    // so therefore lets include every letter
    int digit = input[index] - '0';
    string sex = f[digit];
    for (int i = 0; i < sex.length(); i++)
    {
        // including in it
        getting.push_back(sex[i]);
        get(input, output, f, index + 1, getting);
        getting.pop_back();

        // here we need sequence wise so no need of excluding wala case
    }
}
int main()
{
    string input = "23";
    vector<string> output;
    string getting = "";
    vector<string> f(10);
    f[2] = "abc";
    f[3] = "def";
    f[4] = "ghi";
    f[5] = "jkl";
    f[6] = "mno";
    f[7] = "pqrs";
    f[8] = "tuv";
    f[9] = "wxyz";

    get(input, output, f, 0, getting);

    for (auto i : output)
    {
        cout << i << " ";
    }
}