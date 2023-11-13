/*
    Reverse a given Array

    Problem Statement: You are given an array. The task is to reverse the array and print it.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Using Recursion

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

void helper(int l, int r, vector<int> &nums)
{
    if (l >= r)
        return;
    swap(nums[l], nums[r]);

    helper(l + 1, r - 1, nums);
}

vector<int> reverseArray(int n, vector<int> &nums)
{
    helper(0, n - 1, nums);
    return nums;
}

int main()
{
    int n = 5;
    vector<int> nums = {1, 2, 4, 31, 2};
    vector<int> res;
    res = reverseArray(n, nums);

    for (auto x : res)
    {
        cout << x << " ";
    }
}