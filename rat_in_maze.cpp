#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int maze[][4], int row, int col, int srcy, int srcx, vector<vector<bool>> visited)
{
    if ((srcx >= 0 && srcx < row) && (srcy >= 0 && srcy < col))
    {
        if (maze[srcx][srcy] == 1 && visited[srcx][srcy] == false)
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

void solveMaze(int maze[][4], int row, int col, int srcy, int srcx, vector<vector<bool>> &visited, vector<string> &path, string &output)
{

    // basse case
    // tokhon hoibo jokhon rat destination epoiccha gese
    if (srcx == row - 1 && srcy == col - 1)
    {
        path.push_back(output);
        return;
    }

    // akhon upre jaite lagbo jar liga abar amar dekte lagbo jen ida kora safe ni arr upar jaite lagle amar j-1 korte lagbo

    if (isSafe(maze, row, col, srcy, srcx - 1, visited))
    {
        visited[srcx - 1][srcy] = true;
        output.push_back('u');
        solveMaze(maze, row, col, srcy, srcx - 1, visited, path, output);
        visited[srcx - 1][srcy] = false;
        output.pop_back();
    }

    // right
    if (isSafe(maze, row, col, srcy + 1, srcx, visited))
    {
        visited[srcx][srcy + 1] = true;
        output.push_back('r');
        solveMaze(maze, row, col, srcy + 1, srcx, visited, path, output);
        visited[srcx][srcy + 1] = false;
        output.pop_back();
    }

    // left
    if (isSafe(maze, row, col, srcy - 1, srcx, visited))
    {
        visited[srcx][srcy - 1] = true;
        output.push_back('l');
        solveMaze(maze, row, col, srcy - 1, srcx, visited, path, output);
        visited[srcx][srcy - 1] = false;
        output.pop_back();
    }

    // down
    if (isSafe(maze, row, col, srcy, srcx + 1, visited))
    {
        visited[srcx + 1][srcy] = true;
        output.push_back('d');
        solveMaze(maze, row, col, srcy, srcx + 1, visited, path, output);
        visited[srcx + 1][srcy] = false;
        output.pop_back();
    }
}

int main()
{
    int maze[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    if (maze[0][0] == 0)
    {
        cout << "No path exists " << endl;
        return 0;
    }

    int row = 4;
    int col = 4;

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    // source ki value ko true mark kar dete hai

    visited[0][0] = true;

    vector<string> path;
    string output = "";

    solveMaze(maze, row, col, 0, 0, visited, path, output);

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
}