/*
    Check if an Array is Sorted

    Problem Statement:
    Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

    Note: Two consecutive equal values are considered to be sorted.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Using Brute force

    Time Complexity: O(N^2)
    Space Complexity: O(1)
*/

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                return false;
        }
    }

    return true;
}

/*
    Solution 2: Optimized approach

    Time Complexity: O(N)
    Space Complexity: O(1)
*/

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    bool ans = isSorted(arr, n);
    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}