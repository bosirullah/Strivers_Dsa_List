/*
    Two Sum : Check if a pair with given sum exists in Array

    Problem Statement:
    Given an array of integers arr[] and an integer target.

    1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

    2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

    Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: brute force approach

    Naive Approach(Brute-force approach):

    Intuition:
    For each element of the given array, we will try to search for another element such that its sum is equal to the target.
    If such two numbers exist, we will return the indices or “YES” accordingly.

    Time Complexity: O(N^2), where N = size of the array.
    Reason:
    There are two loops(i.e. nested) each running for approximately N times.

    Space Complexity: O(1) as we are not using any extra space.
*/

// vector<int> twoSum(int n, vector<int> &arr, int target)
// {
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] + arr[j] == target)
//             {
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 return ans;
//             }
//         }
//     }
//     return {-1, -1};
// }

/*
    Solution 2: using hashing

    Better Approach(using Hashing):

    Intuition:
    Basically, in the previous approach we selected one element and then searched for the other one using a loop.
    Here instead of using a loop, we will use the HashMap to check if the other element i.e. target-(selected element)
    exists. Thus we can trim down the time complexity of the problem.

    And for the second variant, we will store the element along will its index in the HashMap. Thus we can easily retrieve
    the index of the other element i.e. target-(selected element) without iterating the array.

    Time Complexity: O(N), where N = size of the array.
    Reason:
    The loop runs N times in the worst case and searching in a hashmap takes O(1) generally.
    So the time complexity is O(N).

    Note: In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In that case,
    the time complexity will be O(N^2). If we use map instead of unordered_map, the time complexity will be O(N* logN) as
    the map data structure takes logN time to find an element.

    Space Complexity: O(N) as we use the map data structure.

    Note: We have optimized this problem enough. But if in the interview, we are not allowed to use the map data structure,
    then we should move on to the following approach i.e. two pointer approach. This approach will have the same time
    complexity as the better approach.
*/

// vector<int> twoSum(int n, vector<int> &nums, int target)
// {
//     unordered_map<int, int> mp;
//     for (int i = 0; i < n; i++)
//     {
//         int num = nums[i];
//         int remSum = target - num;

//         if (mp.find(remSum) != mp.end())
//         {
//             return {mp[remSum], i};
//         }

//         mp[num] = i;
//     }

//     return {-1, -1};
// }

/*
    Solution 3: Optimized approach(only for code variant 1 i.e string)

    Optimized Approach(using two-pointer):

    Intuition:
    In this approach, we will first sort the array and will try to choose the numbers in a greedy way.

    We will keep a left pointer at the first index and a right pointer at the last index. Now until left < right,
    we will check the sum of arr[left] and arr[right]. Now if the sum < target, we need bigger numbers and so we will
    increment the left pointer. But if sum > target, we need to consider lesser numbers and so we will decrement the
    right pointer.

    If sum == target we will return either “YES” or the indices as per the question.
    But if the left crosses the right pointer, we will return “NO” or {-1, -1}.

    Note: For variant 2, we can store the elements of the array along with its index in a new array. Then the rest of the code will be similar. And while returning, we need to return the stored indices instead of returning “YES”. But for this variant, the recommended approach is approach 2 i.e. hashing approach.

    Time Complexity: O(N) + O(N*logN), where N = size of the array.
    Reason:
    The loop will run at most N times. And sorting the array will take N*logN time complexity.

    Space Complexity: O(1) as we are not using any extra space.

    Note: Here we are distorting the given array. So, if we need to consider this change,
    the space complexity will be O(N).
*/

string twoSum(int n, vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    // vector<int> ans = twoSum(n, arr, target);
    // cout << "This is the answer for variant 2: [" << ans[0] << ", "<< ans[1] << "]" << endl;
    return 0;
}