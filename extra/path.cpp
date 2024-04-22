#include <bits/stdc++.h>
using namespace std;

void rec(vector<vector<int>> box, int row, int col, int n, int m, vector<int> &temp, int sum, vector<vector<int>> &output, int &ansum, vector<int> &ansvector)
{

    // base case
    if (row == n - 1 && col == m - 1)
    {
        // i have reached the destination
        // so i will push the sum in the temp vector
        sum += box[row][col];
        temp.push_back(box[row][col]);
        output.push_back(temp);
        if (sum > ansum)
        {
            ansvector = temp;
        }
        temp.pop_back();

        ansum = max(ansum, sum);
        return;
    }

    // now comes the compute or the induction step to make our hypothesis work
    // see we have two choices for each level and i aint returning anythiung

    // one case for moving right
    if (row + 1 < n)
    {
        sum += box[row][col];
        temp.push_back(box[row][col]);
        rec(box, row + 1, col, n, m, temp, sum, output, ansum, ansvector);
        sum -= box[row][col];
        temp.pop_back();
    }
    if (col + 1 < m)
    {
        sum += box[row][col];
        temp.push_back(box[row][col]);
        rec(box, row, col + 1, n, m, temp, sum, output, ansum, ansvector);
        sum -= box[row][col];
        temp.pop_back();
    }
    return;
    // one case for moving down
}

int main()
{
    // creating a matrix for the box
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> box(n, vector<int>(m, 0));
    // enter the values row wise
    cout << "enter the value row   wise that is values of each row first " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "enter the value of box[" << i << "][" << j << "]" << endl;
            cin >> box[i][j];
        }
    }
    cout << "now printing the box that you have entered" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << box[i][j] << " ";
        }
        cout << endl;
    }

    // now that i have created the box lets try my skill of reccursion here to find
    // all the possible paths from 0,0 to n-1,m-1

    // mereko bss dest pohich na hai idhar koi asa constraint nahi hai ke mereko koi kha lega
    // so haule haule bss rec lagake chale jana hai thats it

    // dekh bhai traditional approach se chalta hu phir bad mai modify kar lunga
    // lets try to solve this problem using rec
    vector<int> temp;
    vector<int> ansvector;
    // this is the vector which will be storing as we move forward
    int sum = 0;
    // this is the variable which will be storing the sum of the path
    vector<vector<int>> output;
    int ansum = 0;
    // this is the vector which will be storing all the possible paths that will be existing
    rec(box, 0, 0, n, m, temp, sum, output, ansum, ansvector);
    // now lets print the output
    cout << "the maximum sum that can be obtained is " << ansum << endl;
    cout << "the paths that can be taken are " << endl;
    for (auto i : output)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "the path that will be taken is " << endl;
    for (auto i : ansvector)
    {
        cout << i << " ";
    }
}