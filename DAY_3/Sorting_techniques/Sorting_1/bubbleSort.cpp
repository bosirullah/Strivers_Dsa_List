/*
    Bubble Sort Algorithm

    Problem Statement:
    Given an array of N integers, write a program to implement the Bubble Sorting algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Using Brute Force

    Approach:
    push the max to the last by adjacent swaps

    Time complexity:
    O(N*N), (where N = size of the array), for the worst, and average cases.

    Reason:
    If we carefully observe, we can notice that the outer loop, say i, is running from n-1 to 0
    i.e. n times, and for each i, the inner loop j runs from 0 to i-1. For, i = n-1, the inner loop
    runs n-1 times, for i = n-2, the inner loop runs n-2 times, and so on. So, the total steps
    will be approximately the following: (n-1) + (n-2) + (n-3) + ……..+ 3 + 2 + 1. The summation
    is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2.
    The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we
    can ignore the lower values as well as the constant coefficients. So, the time complexity
    is O(n2). Here the value of n is N i.e. the size of the array.

    Space Complexity: O(1)

*/

void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "After Bubble sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

/*
    Solution 2: Optimized approach (Reducing time complexity for the best case)

    Time Complexity:
    O(N*N) for the worst and average cases and O(N) for the best case. Here, N = size of the array.
    For best case the given array should already be sorted

    Space Complexity: O(1)

*/

void bubble_sort(int arr[], int n)
{
    // bubble sort
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }

    cout << "After Using bubble sort: "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

/*
    Solution 3: Using Recursion

    Time Complexity: O(N2), (where N = size of the array), for the worst, and average cases.

    Reason:
    If we carefully observe, we can notice that the recursion call, is occurring for n times,
    and for each recursion call, the loop j runs from 0 to n-2. For, the range of size n,
    the inner loop runs n-1 times, for the range of size n-1, the inner loop runs n-2 times,
    and so on. So, the total steps will be approximately the following: (n-1) + (n-2) + (n-3)
    + ……..+ 3 + 2 + 1. The summation is approximately the sum of the first n natural numbers i.
    e. (n*(n+1))/2. The precise time complexity will be O(n2/2 + n/2). Previously, we have
    learned that we can ignore the lower values as well as the constant coefficients. So, the
    time complexity is O(n2). Here the value of n is N i.e. the size of the array.

    Space Complexity: O(N) auxiliary stack space.
*/

void bubbleSort(int arr[], int n)
{
    // Base Case: range == 1.
    if (n == 1)
        return;

    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
    }

    // Range reduced after recursion:
    bubbleSort(arr, n - 1);
}

/*
    Solution 4: Using Recursion (optimized approach)

    Time Complexity:
    O(N2) for the worst and average cases and O(N) for the best case. Here, N = size of the array.

    Space Complexity: O(N) auxiliary stack space.
*/

void bubbleSort(int arr[], int n)
{
    // Base Case: range == 1.
    if (n == 1)
        return;

    int didSwap = 0;
    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            didSwap = 1;
        }
    }

    // if no swapping happens.
    if (didSwap == 0)
        return;

    // Range reduced after recursion:
    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Bubble sort: "
         << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    bubble_sort(arr, n);
    return 0;
}