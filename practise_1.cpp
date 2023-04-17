// ajj hum karenge reccursion , divide and conquer aur backtracking ki bhayankar wali revision aaur bss baateinn

// pehle kya karna hai aapko jara batayenge aap ? dekhiye mujhe hai toh bohot dikkat but kya hu kar sakte hai

// pehle hum chalo karte hai merge sort ..aaoo chaliye shuru karte hai

// merge sort ..aab isme hume pehle toh sort karna hota hai aur uske bad karna hota hai do array ko merge ..aab bat yeh hai ke hum move kese karenge iss problem ke liye
// aab hum ase move karenge ke hum ak mid nikalenge aurr kya karenge ki uske right aur left part ko ase hi break karte rahenge
// break utne waqt tak karenge ki woh ak na ho jaye tab kya karenge unn do array ko merge kar denge merge wale concept se

#include <iostream>
using namespace std;

void merge(int arr[], int start, int end)
{

    // dek akhon merge koroner liga amr process kita thakbo

    // first idar liga amr obviously amar left r right part jeda merge hoyar liga aise oida alada koira duida array banaite lagbo
    // then abar oi duida array tika kunda choto kunda boro oi basis e abar oida re main array te boyate lagbo

    int mid = start + (end - start) / 2;

    int len1 = (mid - start) + 1;
    int len2 = end - mid;

    // making the two array
    int *left = new int[len1];
    int *right = new int[len2];

    // now have to copy the elements from the main array to the newly made array

    // copying the left part of the array
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }

    // copying the right part of the array
    // i=0;
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    // now that i have copied both the arrays ..so now we have two arrays which have to be merged on the basis of which is gretaer and which is less

    int z = 0;
    int m = 0;

    int h = start;

    while (z < len1 && m < len2)
    {
        if (left[z] > right[m])
        {
            arr[h++] = right[m++];
        }
        else
        {
            arr[h++] = left[z++];
        }
    }

    while (z < len1)
    {
        arr[h++] = left[z++];
    }

    while (m < len2)
    {
        arr[h++] = right[m++];
    }
    delete[] left;
    delete[] right;
}

void sorting(int arr[], int start, int end)
{

    // base case
    if (start >= end)
    {
        return;
    }

    // ai condition da oi kere ??
    // karon jokhon break korte thakbo akta amn time aibo jokhon either akta hoiya jaibo jar mane start arr end ak position e oi thakbo arr nahole baire jaiboga jeda onk rare

    int mid = start + (end - start) / 2;

    // cholo akhon amar kase abar mid aise akhon kita korum right arrr left part er loge same break up game khelum

    // left part re call koira de
    sorting(arr, start, mid);

    // right part re call koira de
    sorting(arr, mid + 1, end);

    // jokhon ai bhanga bhangi hoiya jaibo akhon abar ami bhangsi amar toh abar jura o lagaite lagbo ...cholo jura lagai
    // akhon jura laganer liga akta function banamu jar nam oi thakbo merge

    merge(arr, start, end);
}

int main()
{
    int arr[] = {1, 5, 8, 3, 45, 34, 77};
    int start = 0;
    int end = 6;

    // int mid =start+(end-start)/2;

    sorting(arr, start, end);

    // now that i have merged sort my array lets see how it works

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}