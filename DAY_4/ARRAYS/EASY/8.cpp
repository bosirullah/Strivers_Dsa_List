/*
    Linear Search in Cpp

    Problem Statement:
    Given an array, and an element num the task is to find if num is present in the given array or not.
    If present print the index of the element or print -1.
*/

#include <iostream>
using namespace std;

/*
    Solution:

    Time Complexity: O(n), where n is the length of the array.
    Space Complexity: O(1)
*/

int linearSearch(int n, int num, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
            return i;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int num = 4;
    int n = sizeof(arr) / sizeof(arr[0]);

    int val = linearSearch(n, num, arr);
    cout << val << endl;
}