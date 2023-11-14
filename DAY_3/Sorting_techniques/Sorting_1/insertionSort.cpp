/*
    Bubble Sort Algorithm

    Problem Statement:
    Given an array of N integers, write a program to implement the Bubble Sorting algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

/*
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

void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    cout << "After Using insertion sort: "
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
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, n);
    return 0;
}