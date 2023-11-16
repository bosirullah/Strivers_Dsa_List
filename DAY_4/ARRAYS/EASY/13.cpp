/*
    Longest Subarray with given Sum K(Positives)

    Problem Statement:
    Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1:

    Naive Approach (Brute-force approach):
    Here, in this approach, we are going to generate all possible subarrays to solve this problem.

    How to generate all possible subarrays?

    We will select all possible starting indices(say i) and all possible ending indices(say j) to generate all possible
    subarrays. The possible starting indices i.e. i can vary from index 0 to index n-1(i.e. The last index). For every
    index i, the possible ending index j can vary from i to n-1. So, the nested loops to generate all possible subarrays
    will be like the following:

    Time Complexity: O(N3) approx., where N = size of the array.
    Reason: We are using three nested loops, each running approximately N times.

    Space Complexity: O(1) as we are not using any extra space.
*/

int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++)
    {
        // starting index
        for (int j = i; j < n; j++)
        { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++)
            {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

/*
    Solution 2:

    Optimizing the Naive Approach (Using two loops):
    Intuition: If we carefully observe, we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].

    Assume previous subarray = arr[i……j-1]
    current subarray = arr[i…..j]
    Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]

    This is how we can remove the third loop and while moving the j pointer, we can calculate the sum.

    Time Complexity: O(N2) approx., where N = size of the array.
    Reason:
    We are using two nested loops, each running approximately N times.

    Space Complexity: O(1) as we are not using any extra space.
*/

int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++)
    {                    // starting index
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++)
        { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

/*
    Solution 3 : Using hash map

    Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
    Reason:
    For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the
    worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using
    a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a
    loop to traverse the array.

    Space Complexity: O(N) as we are using a map data structure.
*/

int getLongestSubarray(vector<int> &a, long long k)
{
    map<long long, int> mp;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
            maxLen = max(maxLen, i + 1);

        long long remSum = sum - k;
        if (mp.find(remSum) != mp.end())
        {
            int len = i - mp[remSum];
            maxLen = max(maxLen, len);
        }

        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }

    return maxLen;
}

/*
    Solution 4:two pointers

    Optimal Approach (Using 2 pointers):

    Time Complexity: O(2*N), where N = size of the given array.
    Reason:
    The outer while loop i.e. the right pointer can move up to index n-1(the last index). Now, the inner while loop
    i.e. the left pointer can move up to the right pointer at most. So, every time the inner loop does not run for n times
    rather it can run for n times in total. So, the time complexity will be O(2*N) instead of O(N2).

    Space Complexity: O(1) as we are not using any extra space.

    Space Complexity: O(1) as we are not using any extra space.
*/

int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n)
    {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n)
            sum += a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
