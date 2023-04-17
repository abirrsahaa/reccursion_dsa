#include <iostream>
using namespace std;
void merge(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;

    int len1 = (mid - start) + 1;
    int len2 = end - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int k = start;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    // int* mergearray=new int[len1+len2];
    int mergeindex = start;

    int i = 0;
    int j = 0;

    while (i < len1 && j < len2)
    {
        if (left[i] < right[j])
        {
            arr[mergeindex++] = left[i++];
        }
        else
        {
            arr[mergeindex++] = right[j++];
        }
    }

    while (i < len1)
    {
        arr[mergeindex++] = left[i++];
    }

    while (j < len2)
    {
        arr[mergeindex++] = right[j++];
    }
}

void sorting(int arr[], int start, int end)
{
    // base case
    // when i will be getting a single element that is the mid and the start is pointing in the same position
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // recursion tu mereko left wala part sort karke dede
    sorting(arr, start, mid);

    // recursion tu mereko right wala part sort karke de de
    sorting(arr, mid + 1, end);

    // hogaya breaking ka randi rona
    // abb merge karde te hai
    merge(arr, start, end);
}

int main()
{

    int arr[] = {1, 5, 8, 3, 45, 34, 77};
    int start = 0;
    int end = 6;

    sorting(arr, start, end);

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}