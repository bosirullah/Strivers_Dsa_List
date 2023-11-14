/*
    Selection Sort Algorithm

    Problem Statement:
    Given an array of N integers, write a program to implement the Selection sorting algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Approach:
    select minimum from the array and swap with the current element
    (in this case is the element at ith index)

    Time complexity:
    O(N*N), (where N = size of the array), for the best, worst, and average cases.

    Reason:
    If we carefully observe, we can notice that the outer loop, say i, is running from 0 to n-2
    i.e. n-1 times, and for each i, the inner loop j runs from i to n-1. For, i = 0,
    the inner loop runs n-1 times, for i = 1, the inner loop runs n-2 times, and so on.
    So, the total steps will be approximately the following: (n-1) + (n-2) + (n-3) + ……..+ 3 + 2 + 1.
    The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2.
    The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we can
    ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2).
    Here the value of n is N i.e. the size of the array.

    Space Complexity: O(1)
*/

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }

        swap(arr[mini], arr[i]);
    }

    cout << "After selection sort: "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before selection sort: "
         << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    selection_sort(arr, n);
    return 0;
}