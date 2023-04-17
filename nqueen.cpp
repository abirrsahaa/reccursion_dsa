// #include <iostream>
// #include <vector>
// using namespace std;
// void printfull(vector<vector<int>> &board, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << board[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl
//          << endl;
// }

// bool is_Safe(vector<vector<int>> &board, int row, int col, int n)
// {
//     // check left row wise
//     while (row >= 0)
//     {
//         if (board[row][col] == 1)
//         {
//             return false;
//         }
//         row--;
//     }

//     // check upper left diagonal
//     int i = row;
//     int j = col;
//     while (i >= 0 && j >= 0)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//         i--;
//         j--;
//     }

//     // check lower left diagonal
//     i = row;
//     j = col;
//     while (i < n && j >= 0)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//         i++;
//         j--;
//     }

//     // idhar tak aiye ho uska matlab yahu hai ke rasta saf hai

//     return true;
// }

// void solve(vector<vector<int>> &board, int col, int n)
// {
//     // base case
//     if (col >= n)
//     {
//         printfull(board, n);
//         return;
//     }

//     // ak case solve kar leta hu baki recccursion sanmbhal lega
//     for (int row = 0; row < n; row++)
//     {
//         if (is_Safe(board, row, col, n))
//         {
//             board[row][col] = 1;
//             // reccursion call kar deta hu baki columns ke liye
//             solve(board, col + 1, n);
//             // baki jab ho jaye toh phir baki sol ke liye backtracking kar leta hu
//             board[row][col] = 0;
//         }
//     }
// }
// int main()
// {
//     int n = 4;
//     vector<vector<int>> board(0, vector<int>(n, 0));
//     int col = 0;

//     solve(board, col, n);
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void printfull(vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

bool is_Safe(vector<vector<int>> &board, int row, int col, int n)
{
    // check left row wise
    int i = row;
    int j = col;
    while (j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        j--;
    }

    // check upper left diagonal
    // int i=row;
    // int j=col;
    i = row;
    j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    // check lower left diagonal
    // i=row;
    // j=col;
    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i++;
        j--;
    }

    // If all checks pass, return true
    return true;
}

void solve(vector<vector<int>> &board, int col, int n)
{
    // base case
    if (col >= n)
    {
        printfull(board, n);
        return;
    }

    // ak case solve kar leta hu baki recursion sanmbhal lega
    for (int row = 0; row < n; row++)
    {
        if (is_Safe(board, row, col, n))
        {
            board[row][col] = 1;
            // recursion call kar deta hu baki columns ke liye
            solve(board, col + 1, n);
            // baki jab ho jaye toh phir baki sol ke liye backtracking kar leta hu
            board[row][col] = 0;
        }
    }
    return;
}

int main()
{
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int col = 0;

    solve(board, col, n);
    return 0;
}
