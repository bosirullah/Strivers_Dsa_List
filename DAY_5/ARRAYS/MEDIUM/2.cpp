/*
    Sort an array of 0s, 1s and 2s

    Problem Statement:
    Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using
    inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1 : by using sort() stl

    Time Complexity : O(NlogN), where N is the number of elements in the array.
    Space Complexity: O(1), as no extra space is used.
*/

void sortColors(vector<int> &nums, int n)
{
    sort(nums.begin(), nums.end());
}

/*
    Solution 2: Better approach

    Time Complexity: O(N) + O(N), where N = size of the array.
    First O(N) for counting the number of 0’s, 1’s, 2’s, and second O(N) for placing them correctly in the original array.

    Space Complexity: O(1) as we are not using any extra space.
*/

void sortColors(vector<int> &nums, int n)
{
    int count_0 = 0, count_1 = 0, count_2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            count_0++;
        else if (nums[i] == 1)
            count_1++;
        else
            count_2++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i < count_0)
        {
            nums[i] = 0;
        }
        else if (i < (count_0 + count_1))
        {
            nums[i] = 1;
        }
        else
            nums[i] = 2;
    }
}

/*
    Solution 3: Using 3 pointers(Optimal approach)

    Algorithm / Intuition
    This problem is a variation of the popular Dutch National flag algorithm.

    This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:

    arr[0….low-1] contains 0. [Extreme left part]
    arr[low….mid-1] contains 1.
    arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
    The middle part i.e. arr[mid….high] is the unsorted segment. So, hypothetically the array with different markers
    will look like the following:

    In our case, we can assume that the entire given array is unsorted and so we will place the pointers accordingly. For example, if the given array is: [2,0,2,1,1,0], the array with the 3 pointers will look like the following:

    Here, as the entire array is unsorted, we have placed the mid pointer in the first index and the high pointer in the last index. The low is also pointing to the first index as we have no other index before 0. Here, we are mostly interested in placing the ‘mid’ pointer and the ‘high’ pointer as they represent the unsorted part in the hypothetical array.

    Time Complexity: O(N), where N = size of the given array.
    Reason:
    We are using a single loop that can run at most N times.

    Space Complexity: O(1) as we are not using any extra space.
*/

void sortArray(vector<int> &arr, int n)
{

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortColors(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}