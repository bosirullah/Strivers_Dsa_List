/*
    Remove Duplicates in-place from Sorted Array

    Problem Statement:
    Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element
    appears only once. The relative order of the elements should be kept the same.

    If there are k elements after removing the duplicates, then the first k elements of the array should hold the final
    result. It does not matter what you leave beyond the first k elements.

    Note: Return k after placing the final result in the first k slots of the array.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Brute Force

    Intuition:
    We have to think of a data structure that does not store duplicate elements. So can we use a Hash set? Yes! We can.
    As we know HashSet only stores unique elements.

    Time complexity: O(n*log(n))+O(n)
    Space Complexity: O(n)
*/

// int removeDuplicates(int arr[], int n)
// {
//     set<int> st;
//     for (int i = 0; i < n; i++)
//     {
//         st.insert(arr[i]);
//     }

//     int k = st.size();
//     int i = 0;
//     for (int x : st)
//     {
//         arr[i++] = x;
//     }

//     return k;
// }

/*
    Solution 2: Two pointers

    Intuition: We can think of using two pointers ‘i’ and ‘j’, we move ‘j’ till we don’t get a number arr[j] which is
    different from arr[i]. As we got a unique number we will increase the i pointer and update its value by arr[j].

    Time Complexity: O(N)
    Space Complexity: O(1)
*/

int removeDuplicates(int arr[], int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = removeDuplicates(arr, n);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}