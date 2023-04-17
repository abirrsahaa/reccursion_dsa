// QUESTION:  to find all the possible parenthesis making combinations
//
//
//
//
//
// CONCEPT:- PURE RECCURSIVE THINKING APPROACH
// also we have the same approach of include and exclude
//
//
//
//
// NOW IDA TUI KEMNE KORBI BA THINKING APPROACH TA KITA?????
//
//
//
//
//
//
// here we will be having number of pairs of parenthesis ....
// therefore there will be same number of open and closed brackets
// and we know that there for a valid parenthesis the number of open and closed brackets should be same
// now what we can do is we can apply reccursion until we run out of brackets
// and yes to apply a closed bracket it is must that a open bracket should be there
// which means that the number of closed bracket at that instant has to be more than the open bracket
// and when we will be out of brackets that means we have got a result case
// #include <iostream>
// #include <vector>
// using namespace std;
// void getting(string &result, vector<string> &ans, int open, int closed)
// {
//     // base case
//     // mane jokhon amar kase shob bracket sesh
//     if (open == 0 && closed == 0)
//     {
//         ans.push_back(result);
//         return;
//     }

//     // ak case solve kar dete hai baki ka reccurrsion dekh lega
//     // to include a open bracket the consdition should be just that it is greater than 0
//     if (open > 0)
//     {
//         result.push_back('(');
//         getting(result, ans, open - 1, closed);
//         // as we are passing as a reference so backtracking is required as we have to get
//         // all possible solutions
//         result.pop_back();
//     }

//     // now open bracket is included now to include close bracket
//     // what we should be doing is we need to keep the consition to include close brackets in mind
//     // to include close brackets obviously there should exists open brackets for the same
//     // thereforwe it could be also said that the number of closed brackets should be more than the
//     // open brackets
//     if (closed > 0 && closed > open)
//     {
//         result.push_back(')');
//         getting(result, ans, open, closed - 1);
//         // backtrack to banta hua na boss
//         result.pop_back();
//     }
//     return;
// }
// int main()
// {
//     string result = "";
//     int pairs;
//     cout << "enter the number of pairs" << endl;
//     cin >> pairs;
//     vector<string> ans;
//     int open = pairs;
//     int closed = pairs;
//     getting(result, ans, open, closed);
//     for (auto i : ans)
//     {
//         cout << i << " ";
//     }
// }

// QUESTION:- to find all possible combinatons using a keypad phone
// now consider the input is 23
// and the possible combinations would be from "abc" and "def";

// CONCEPT: INCLUSION AND EXCLUSION
// FOR LOOP IN RECCURSION

// now the input to this problem could have two ways
// either we would be getting a string output
// which would be much easier as we could easily traverse through it
// another way could be a integer inout
// where we have to additional work of reversing it and then extracting every digit in it

// #include <iostream>
// #include <vector>
// using namespace std;
// // now the main thing is what is the approach
// // dekh question hoise all possible combinations tar mane kono na kono bhabe first e amar
// // inclusion and exclusion principle diya dekhte lagbo oi
// // and guess what inclusion and exclusion principle ida te o lagbo just aikane aktar jagat duida string
// // and just problem da re shajaite oi ja bhabte lagbo rki
// void getting(string input, string &output, int index, vector<string> &ans, vector<string> &mapping)
// {
//     // base case
//     if (index >= input.length())
//     {
//         ans.push_back(output);
//         return;
//     }

//     int digit = input[index] - '0';
//     string da = mapping[digit];

//     // dekh akhon amar kase prothom digit aiya porse and prothom digit r mapp kora
//     // array jeta joto oi numner r character thakte pare shob aiya porse
//     // akhon amar ki korte lagbo amar just oidar liga include exclude r khela khelte lagbo
//     // ami prohtom letter ta re e rakhum and index ta barai dimu porer digit r letter rakhar liga
//     for (int i = 0; i < da.length(); i++)
//     {
//         // including the first element and eventually every element of that digit by reccursion through for loop
//         output.push_back(da[i]);
//         getting(input, output, index + 1, ans, mapping);
//         // akhon backtracking toh lagbo oi
//         output.pop_back();
//     }
//     // return;
// }
// int main()
// {
//     string input = "23";
//     string output = "";
//     // i got tricked in the below line as i forgot how to declare a string vector and
//     // that i need to specify the size of it
//     // and if later it is found that it wasnt required find out why then did we use it here?
//     vector<string> mapping(10);
//     mapping[2] = "abc";
//     mapping[3] = "def";
//     mapping[4] = "ghi";
//     mapping[5] = "jkl";
//     mapping[6] = "mno";
//     mapping[7] = "pqrs";
//     mapping[8] = "tuv";
//     mapping[9] = "wxyz";
//     int index = 0;
//     vector<string> ans;
//     getting(input, output, index, ans, mapping);
//     for (auto i : ans)
//     {
//         cout << i << " ";
//     }
// }

// now lets play some games baby with logic and reccursion
// rat in a maze
// nth queen
// soduko solver
// permutations in a string

// QUESTION: RAT IN A MAZE

// PROBLEM FACED :DECLARING A 2D ARRAY
// vector<vector<bool>> visited(row, vector<bool>(col, false));

// CONCEPT : MOSTLY LOGICAL THINKING
//  QUITE EASY IF UNDERSTAND
// HIGHLY APPLICABILITY AND UNDERSTANDING OF BACKTRACKING

// the maze that is provided
//  int maze[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int srcx, int srcy, int row, int col, vector<vector<bool>> &visited, int maze[4][4])
{
    // safe kokhon hoibo
    // jokhon obviously maze r modhey ghor ta
    // oidate age gese na
    // and maze r modhey 1 ase jayoner liga
    if ((srcx >= 0 && srcx < row) && (srcy >= 0 && srcy < col))
    {
        if (visited[srcx][srcy] == false && maze[srcx][srcy] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

void getting(int srcx, int srcy, int row, int col, vector<vector<bool>> &visited, int maze[4][4], vector<string> &ans, string &output)
{
    // base case
    // base case tokhon e hoibo jokhon destination e poicha jamu
    if (srcx == row - 1 && srcy == col - 1)
    {
        ans.push_back(output);
        return;
    }

    // akhon akta case shob direction er liga solve koira dou
    // baki toh reccursion kakku ase oi dekhon r liga

    // upore jayoner liga
    // row paltaibo column na
    // srcx-1

    if (isSafe(srcx - 1, srcy, row, col, visited, maze))
    {
        output.push_back('u');
        // call with srcx+1
        visited[srcx - 1][srcy] = true;
        getting(srcx - 1, srcy, row, col, visited, maze, ans, output);
        // hoiya gese ak case tar mane na hoile firot aibo tahole backtrack lagbo
        output.pop_back();
        visited[srcx - 1][srcy] = false;
    }

    // left jayoner liga
    // column paltaibo row na
    // srcy-1

    if (isSafe(srcx, srcy - 1, row, col, visited, maze))
    {
        output.push_back('l');
        // call with srcx+1
        visited[srcx][srcy - 1] = true;
        getting(srcx, srcy - 1, row, col, visited, maze, ans, output);
        // hoiya gese ak case tar mane na hoile firot aibo tahole backtrack lagbo
        output.pop_back();
        visited[srcx][srcy - 1] = false;
    }

    // niche jayoner liga
    // row paltaibo column na
    // srcx+1

    if (isSafe(srcx + 1, srcy, row, col, visited, maze))
    {
        output.push_back('d');
        // call with srcx+1
        visited[srcx + 1][srcy] = true;
        getting(srcx + 1, srcy, row, col, visited, maze, ans, output);
        // hoiya gese ak case tar mane na hoile firot aibo tahole backtrack lagbo
        output.pop_back();
        visited[srcx + 1][srcy] = false;
    }

    // right jayoner liga
    // col paltaibo row na
    // srcy+1

    if (isSafe(srcx, srcy + 1, row, col, visited, maze))
    {
        output.push_back('r');
        // call with srcx+1
        visited[srcx][srcy + 1] = true;
        getting(srcx, srcy + 1, row, col, visited, maze, ans, output);
        // hoiya gese ak case tar mane na hoile firot aibo tahole backtrack lagbo
        output.pop_back();
        visited[srcx][srcy + 1] = false;
    }
}
int main()
{
    // cholo ja amrare deyoner tara diya laise akhon ida diya ja kheloner khelte lagbo
    int maze[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int row = 4;
    int col = 4;
    int srcx = 0;
    int srcy = 0;
    // akhon dekh ami ida bujhum kemne ami already oi jagat gesi ni
    // karon jodi na giya thaki tahole toh jaite parum
    // but giya thakle toh jaite partam na
    // toh akta kaj kori same ditto arekta boolean matrix banai and shobdi re false banai rakhi
    // karon akhono kunodate gesi na except the first one
    // arr jodi indur ta re pathai oi oi ghore tahole oi dare true koira dimu jodi
    // ha oi rasta da re r na choose kore
    // arr backtrack r khetre mone rakhis
    // jokhon firot aisos mane kita rasta da re bair korsos toh thik oi
    // but oi rasta da jen gesos na oi dare false korte bhuklis na kintu
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    if (maze[0][0] == 0)
    {
        return 0;
    }

    visited[0][0] = true;
    vector<string> ans;
    string output = "";
    getting(srcx, srcy, row, col, visited, maze, ans, output);
    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}