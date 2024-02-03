// lets first design my algorithm for this problem
// i would need an array where i will be storing every subsequences
// and with that storing of subsequences i will be storing the curr sum also just to check if i have met the sum
// on successful meeting of the sum i will update the min size element
// the base case would be when the index reaches the end of the array
#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> abir, vector<int> &manchita, int &currsum, int target, int &min_size, int size, int index)
{
    // base case
    if (index >= size)
    {
        return;
    }
    // solve one case and leave the rest
    // if i am not taking this element
    helper(abir, manchita, currsum, target, min_size, size, index + 1);
    // if i am taking this element
    manchita.push_back(abir[index]);
    currsum += abir[index];
    if (currsum == target)
    {
        if (manchita.size() < min_size)
        {
            min_size = manchita.size();
        }
    }
    helper(abir, manchita, currsum, target, min_size, size, index + 1);
}

int getting_minimum(vector<int> abir, int target)
{
    int size = abir.size();
    // creating the vector where i will be storing my subsequences
    vector<int> manchita;

    // creating the curr sum variable
    int currsum = 0;
    // creating the min_size variable and initializing it with the maximum variable
    int min_size = INT_MAX;
    helper(abir, manchita, currsum, target, min_size, size, 0);
    cout << "the minimum element needed is -> " << min_size << endl;
}

int main()
{
    vector<int> abir = {1, 2, 3};
    int target = 5;
    getting_minimum(abir, target);
    return 0;
}