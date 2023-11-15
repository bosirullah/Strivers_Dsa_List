/*
    Merge Sort Algorithm

    Problem:
    Given an array of size n, sort the array using Merge Sort.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution :

    Intuition:
    Merge Sort is a divide and conquers algorithm, it divides the given array into equal parts
    and then merges the 2 sorted parts.

    There are 2 main functions :
    1. merge(): This function is used to merge the 2 halves of the array. It assumes that both
    parts of the array are sorted and merges both of them.

    2. mergeSort(): This function divides the array into 2 parts. low to mid and mid+1 to high where,
        low = leftmost index of the array
        high = rightmost index of the array
        mid = Middle index of the array

    3. We recursively split the array, and go from top-down until all sub-arrays size becomes 1.

    Time complexity: O(nlogn)
    Reason:
    At each step, we divide the whole array, for that logn and we assume n steps are taken
    to get sorted array, so overall time complexity will be nlogn

    Space complexity: O(n)
    Reason:
    We are using a temporary array to store elements in sorted order.

    Auxiliary Space Complexity: O(n)
*/

void merge(int arr[], int low, int mid, int high)
{
    int left = low, right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int arr[] = {9, 4, 7, 6, 3, 1, 5};
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}