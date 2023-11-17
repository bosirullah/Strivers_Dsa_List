/*
    Find the Majority Element that occurs more than N/2 times

    Problem Statement:
    Given an array of N integers, write a program to return an element that occurs more than
    N/2 times in the given array. You may consider that such an element always exists in the
    array.
*/

/*
    Solution 1: Brute force approach

    Time Complexity: O(N^2),
    where N = size of the given array. Reason: For every element of the array the inner loop runs
    for N times. And there are N elements in the array. So, the total time complexity is O(N2).

    Space Complexity: O(1) as we use no extra space.
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v)
{

    // size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            // counting the frequency of v[i]
            if (v[j] == v[i])
            {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

/*
    Solution 2 (Better):

    Intuition:
    Use a better data structure to reduce the number of look-up operations and hence the time complexity.
    Moreover, we have been calculating the count of the same element again and again – so we have to reduce that also.

    Time Complexity: O(N*logN) + O(N), where N = size of the given array.
    Reason:
    We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements.
    So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2)
    times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst
    case, it will be O(N^2).

    Space Complexity: O(N) as we are using a map data structure.
*/

int majorityElement(vector<int> nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for (auto x : nums)
    {
        mp[x]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[nums[i]] > n / 2)
            return nums[i];
    }

    return -1;
}

/*
    Solution 3: Using Moore's voting algorithm

    Optimal Approach: Moore’s Voting Algorithm:
    Intuition:
    If the array contains a majority element, its occurrence must be greater than the floor(N/2).
    Now, we can say that the count of minority elements and majority elements is equal up to a
    certain point in the array. So when we traverse through the array we try to keep track of the
    count of elements and the element itself for which we are tracking the count.

    After traversing the whole array, we will check the element stored in the variable. If the
    question states that the array must contain a majority element, the stored element will be that
    one but if the question does not state so, then we need to check if the stored element is the
    majority element or not. If not, then the array does not contain any majority element.

    Time Complexity: O(N) + O(N), where N = size of the given array.
    Reason:
    The first O(N) is to calculate the count and find the expected majority element. The second one
    is to check if the expected element is the majority one or not.

    Note: If the question states that the array must contain a majority element, in that case,
    we do not need the second check. Then the time complexity will boil down to O(N).

    Space Complexity: O(1) as we are not using any extra space.
*/

int majorityElement(vector<int> arr)
{
    // size of the array
    int n = arr.size();
    int ele = 0; // element
    int cnt = 0; // count

    // applying the algorithm:
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            ele = arr[i];
        }
        else if (ele == arr[i])
            cnt++;
        else
            cnt--;
    }

    // checking if the stored element is the majority element:
    int cnt1 = 0;
    for (auto x : arr)
    {
        if (x == ele)
            cnt1++;
    }

    if (cnt1 > (n / 2))
        return ele;
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
