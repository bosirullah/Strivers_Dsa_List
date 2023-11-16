/*
    Longest Subarray with sum K | [Postives and Negatives]

    Problem Statement:
    Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1 & 2 are same as prev quesiton

    Solution 3:
    Optimal Approach (Using Hashing):

    Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
    Reason:
    For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the
    worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using a
    map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop
    to traverse the array.

    Space Complexity: O(N) as we are using a map data structure.
*/

int getLongestSubarray(vector<int> &a, int k)
{
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        // calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        // Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = {-1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
