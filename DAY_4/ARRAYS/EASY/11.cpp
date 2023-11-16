/*
    Count Maximum Consecutive One’s in the array

    Problem Statement:
    Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution : Using Kadane's Algorithm

    Time Complexity: O(N) since the solution involves only a single pass.
    Space Complexity: O(1) because no extra space is used.
*/

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max_so_far = INT_MIN, max_ending_here = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                max_ending_here++;
            else
                max_ending_here = 0;

            max_so_far = max(max_so_far, max_ending_here);
        }

        return max_so_far;
    }
};

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    Solution obj;
    int ans = obj.findMaxConsecutiveOnes(nums);
    cout << "The maximum  consecutive 1's are " << ans << endl;
    return 0;
}