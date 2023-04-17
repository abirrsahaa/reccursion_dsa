// printing the subsequences

// kemne korsos ba bhabsos "?"
// akhon kemne korsi hoise
// step 1 : ami jani jen amar inclusion and exclusion principle lagbo karon ida subsequence
// step 2: akhon string ase tar  mane ami index r opore khelte parum traverse koira koira
// step 3: kita arr aktu backtracking lagaisi r ki jodi khela da by reference kheli
// step 4: subsequence may be mukhosto hoiya gese best hoibo
// step 5: reccursion tree banaiya code flow and thinking process ta abar bhabo

// #include <iostream>
// #include <vector>
// using namespace std;
// void bring(string input, int index, int n, vector<string> &ans, string &output)
// {
//     // base case as we are using recursion and moreover for subsequences we will be using the include and exclude principle
//     if (index >= n)
//     {
//         ans.push_back(output);
//         return;
//     }

//     // now we would be using the include and exclude principle
//     // for including we will be just including the element in that index and we will be passing on the index forward
//     output.push_back(input[index]);
//     // calling the recursion for the next index
//     bring(input, index + 1, n, ans, output);
//     // now as we are passing the output string as a reference we would have to use the backtracking abilithy
//     output.pop_back();

//     // now that include is done another thing we can do is to not include the lement present in that index
//     bring(input, index + 1, n, ans, output);
// }
// int main()
// {
//     string input = "abcd";
//     int n = input.size();
//     int index = 0;
//     vector<string> ans;
//     string output = "";
//     bring(input, index, n, ans, output);

//     // now by this line my all possible substrings would be ready in the ans vector
//     // lets just print the ans vector to get our subsequences
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
// }
// }

// }

// }

// }
//
//
//
//
//
//
//

// now the question is about minimum elements required for sum
// vector<int> arr{1,2} and target int target = 5

// kemne korsos ba bhabsos "?"

// dekh aikhane amar kase array asilo arr target asilo
// toh atate kita korsi first e bhabsi jen shobdi diya minus korte thakum
// jotokhan na zero hoi ..and jodi zero hoiya jaiga target minus korte korte
// tahole tar mane kita ida akbar minus hoise toh 0 jeda return korbo tar loge plus 1 koira dimu
// akhon ai problem dar bhetore jehetu amar kase akta array ase and ami shob elements kaje lagaite lagbo
// toh ami ai date FOR LOOP  r use da korum ai rokom problem r modhey logic same thake
// but amra kemne operation shobdi elements r opore perform kori oitar opore onk  kisu depend kore

// akhon code r logic aslo jen ami protek elemet diya kadum mane minus korum
// and jotobar e jaibo ami oidar minimum bair koira dimu
// tar liga ami akta mini already INT_MAX diya define koira raikha dimu
// and for loop sesh mane kita amar shob array r elements diya ami kaj korai laisi
// tar mane amar oi operation r liga minimum number of steps aiya porse mini r modhey
// jar foleh ami for loop r pore mini da re oi return koira dimu ...

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <limits.h>
// using namespace std;
// int result(vector<int> &arr, int target)
// {

//     // now what would be the base case
//     if (target == 0)
//     {
//         return 0;
//     }

//     if (target < 0)
//     {
//         return INT_MAX;
//     }

//     // age solve koira loi dek age tui mini re define kor aikhane to prottek r liga akta min decide hoibo ager tika na
//     int mini = INT_MAX;
//     // akhon dek amar akhon koaj korte lagbo ashol da jen ami shob elements r liga array r modhey loop call koira ditasi
//     for (int i = 0; i < arr.size(); i++)
//     {
//         // ashol kaj ta toh aikhane oi hoibo
//         // dek jodi zero aiye tar mane kita idA AK bar kada hoise properly tar mane oi ak bar paite gele amar return r loge 0 r loge ak plus korte lagbo
//         int ans = result(arr, target - arr[i]);
//         if (ans != INT_MAX)
//         {
//             ans = ans + 1;
//             mini = min(mini, ans);
//         }
//     }
//     return mini;
// }

// int main()
// {
//     vector<int> arr{1, 2};
//     int target = 5;
//     // int mini = INT_MAX;
//     int minimum = result(arr, target);
//     cout << "the minimum times is : " << minimum;
// }
//
//
//
//
//
//
//
//
//
//
//

// now the question is about how many maximum  times the rope can be cut
//   int n = 7;
//   int x = 5;
//   int y = 2;
//   int z = 2;

// kemne korsos ba bhabsos "?"

// dekh ai question da rr minimum elements for sum problem dar modhedy kintu
// bindu matro difference nai ...purely logic r basis e

// tahole difference ta kita difference hoise amar kase array nai akhon
// amar kase 3 da different element ase jeda milla solution set banaise

// akhon dek logic toh aikhane o same lagbo jen prottek ta element e giya ami minus korum target ta re
// jotokhan na ami 0 paitasi karon jodi paiya lai tar mane hoise akta way paiya laisi
// tar mane jei 0 da return hoitase oidar loge plus 1 koira dimu
// akhon maximum r liga max bair koira lamu
// akhon main kotha hoise jen max toh ami bair koira lailam hoile ager moto
// for loop lagaiya jodi array te amar shobdi solution set r elements thaklo hoile

// but jehetu different ki ase ami differetly bair korum jen prottek ta diya koto ways aitase
// and after every element sesh hoyar por mane ki amar kase 3 da set of no of ways ase
// akhon ami oida tika max bair koira lamu by max(a,(max(b,c)))

// #include <iostream>
// #include <limits.h>
// using namespace std;

// int result(int n, int x, int y, int z)
// {
//     // base case
//     if (n == 0)
//     {
//         return 0;
//     }

//     if (n < 0)
//     {
//         return INT_MIN;
//     }

//     // now the dimag wala part
//     // dek aikhane jehetu amar kase array ba vector nai tar mane kita ami kintu for loop r dara aida korte partam na
//     // but ditto same logic lagaute parum kintu kemne karon ja kortam akta forloop lagaiya oida e akhon n number of variabkes r liga korte lagbo
//     int ans1 = result(n - x, x, y, z) + 1;
//     int ans2 = result(n - y, x, y, z) + 1;
//     int ans3 = result(n - z, x, y, z) + 1;

//     return max(ans1, max(ans2, ans3));
// }
// int main()
// {
//     int n = 7;
//     int x = 5;
//     int y = 2;
//     int z = 2;

//     int maximum = result(n, x, y, z);
//     cout << maximum;
//     int ans;

//     if (maximum > 0)
//     {
//         ans = maximum;
//     }
//     else
//     {
//         ans = 0;
//     }

//     cout << "the maximum times the rope can be cut is : " << ans;
//     return 0;
// }

// have to understand the reccursion tree of the above solution .........

//
//
//
//
//
//
//
//
//
//
//
//
//

// now is the question of maximum non - adjacent sum

// vector<int> arr{1, 2, 3, 1, 3, 5, 8, 1, 9}; le le yeh hai tera input
// dek question koise maximim sum of non adjacene elements tar mane kita tui jodi akta include koros tar mane tui r porer ta include korte parti na arr
// but tui jodi include na koros tahole abar tui obviously porer tat jaite parbi akhon tui oikhane giya ki koros ki na koros ida tor bepar

// kemne korsos ba bhabsos "?"

// dekh ai sum da tor tree banaiya dekte lagbo nahole kintu hoito na ..karon tui
// tree na korle tui thinking process ta bujdi na

// #include <iostream>
// #include <limits.h>
// #include <vector>
// using namespace std;
// void result(vector<int> &arr, int index, int &maxi, int sum)
// {
//     // base case
//     if (index >= arr.size())
//     {
//         maxi = max(maxi, sum);
//         return;
//     }

//     // include kortasi sum e idare
//     sum = sum + arr[index];
//     result(arr, index + 2, maxi, sum);
//  //backtrack lagdo na karon aikahne by reference pass kortasu na ami jodi pass kortam toilre laglo hoile

//     // ami idare kisu korsi na baki jani na ]
//     result(arr, index + 1, maxi, sum);

//     // return max(maxi, sum);
// }
// int main()
// {
//     vector<int> arr{1, 2, 3, 1, 3, 5, 8, 1, 9};
//     int index = 0;
//     int maxi = INT_MIN;
//     int sum = 0;
//     result(arr, index, maxi, sum);

//     cout << "the maximum sum of the non adjacent elements is : --> " << maxi;
// }
