/*
    Find Second Smallest and Second Largest Element in an array

    Problem Statement: Given an array, find the second smallest and second largest element in the array.
    Print ‘-1’ in the event that either of them doesn’t exist.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: (Brute Force) [this approach only works if there are no duplicates]

    Intuition:
    What do we do to find the largest or the smallest element present in an array? We ideally sort them and the first
    element would be the smallest of all while the last element would be the largest. Can we find the second-smallest
    and second-largest using a similar approach?

    Time Complexity: O(NlogN), For sorting the array
    Space Complexity: O(1)
*/

void getElements(int arr[], int n)
{
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl; // edge case when only one element is present in array
    sort(arr, arr + n);
    int small = arr[1];
    int large = arr[n - 2];
    cout << "Second smallest is " << small << endl;
    cout << "Second largest is " << large << endl;
}

/*
    Solution 2: (Better Solution)

    Intuition:
    Even though we want to have just the second smallest and largest elements, we are still sorting the entire array for that
    and thus increasing the time complexity. Can we somehow try to not sort the array and still get our answer?

    Time Complexity: O(N), We do two linear traversals in our array
    Space Complexity: O(1)
*/

void getElements(int arr[], int n)
{
    int max_ele = INT_MIN, min_ele = INT_MAX;
    int second_max_ele = INT_MIN, second_min_ele = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        max_ele = max(max_ele, arr[i]);
        min_ele = min(min_ele, arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != max_ele)
        {
            second_max_ele = max(second_max_ele, arr[i]);
        }
        if (arr[i] != min_ele)
        {
            second_min_ele = min(second_min_ele, arr[i]);
        }
    }

    cout << "Second smallest is " << second_min_ele << endl;
    cout << "Second largest is " << second_max_ele << endl;
}

/*
    Solution 3(Best Solution)

    Intuition:
    In the previous solution, even though we were able to bring down the time complexity to O(N), we still needed to do two
    traversals to find our answer. Can we do this in a single traversal by using smart comparisons on the go?

    Time Complexity: O(N), Single-pass solution
    Space Complexity: O(1)
*/

void getElements(int arr[], int n)
{
    int max_ele = INT_MIN, min_ele = INT_MAX;
    int second_max_ele = INT_MIN, second_min_ele = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max_ele)
        {
            second_max_ele = max_ele;
            max_ele = arr[i];
        }
        else if (arr[i] > second_max_ele && arr[i] != max_ele)
        {
            second_max_ele = arr[i];
        }

        if (arr[i] < min_ele)
        {
            second_min_ele = min_ele;
            min_ele = arr[i];
        }
        else if (arr[i] < second_min_ele && arr[i] != min_ele)
        {
            second_min_ele = arr[i];
        }
    }

    cout << "Second smallest is " << second_min_ele << endl;
    cout << "Second largest is " << second_max_ele << endl;
}

int main()
{
    int arr[] = {1, 2, 4, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    getElements(arr, n);
    return 0;
}
