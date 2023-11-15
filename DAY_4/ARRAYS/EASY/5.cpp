/*
    Rotate Array

    Problem statement:
    Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: using extra space

    Time Complexity: O(N) , two traversals
    Space Complexity: O(N), for the extra space
*/

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        vector<int> temp(nums.begin() + n - k, nums.end());

        for (int i = 0; i < n - k; i++)
        {
            temp.push_back(nums[i]);
        }

        int j = 0;
        for (auto x : temp)
        {
            nums[j++] = x;
        }
    }

    /*
        Solution 2: optimized approach

        Time Complexity: O(N) , two traversals
        Space Complexity: O(1)
    */

    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int k = 3;

    Solution s;
    s.rotate(v, k);

    cout << "After rotating the array: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
}