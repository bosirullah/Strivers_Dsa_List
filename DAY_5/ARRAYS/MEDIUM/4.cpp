/*
    Kadane’s Algorithm : Maximum Subarray Sum in an Array

    Problem Statement:
    Given an integer array arr, find the contiguous subarray (containing at least one number) which
    has the largest sum and returns its sum and prints the subarray.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Brute force approach

    Time Complexity: O(N^2), where N = size of the array.
    Reason:
    We are using two nested loops, each running approximately N times.

    Space Complexity: O(1) as we are not using any extra space.
*/

int maxSubarraySum(int arr[], int n)
{
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            // current subarray = arr[i.....j]

            // add the current element arr[j]
            //  to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

/*
    Intuition:
    The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0.
    A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the
    subarray with maximum sum.

    Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum
    variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider
    any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.

    Thus we can solve this problem with a single loop.

    Time Complexity: O(N), where N = size of the array.
    Reason:
    We are using a single loop running N times.

    Space Complexity: O(1) as we are not using any extra space.
*/

long long maxSubarraySum1(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    // if (maxi < 0) maxi = 0;

    return maxi;
}

/*
    Algorithm / Intuition
    There might be more than one subarray with the maximum sum. We need to print any of them.

    Intuition:
    Our approach is to store the starting index and the ending index of the subarray. Thus we can easily get the
    subarray afterward without actually storing the subarray elements.

    If we carefully observe our algorithm, we can notice that the subarray always starts at the particular index where the
    sum variable is equal to 0, and at the ending index, the sum always crosses the previous maximum sum(i.e. maxi).

    So, we will keep a track of the starting index inside the loop using a start variable.
    We will take two variables ansStart and ansEnd initialized with -1. And when the sum crosses the maximum sum, we will
    set ansStart to the start variable and ansEnd to the current index i.e. i.
    The rest of the approach will be the same as Kadane’s Algorithm.

    Time Complexity: O(N), where N = size of the array.
    Reason:
    We are using a single loop running N times.

    Space Complexity: O(1) as we are not using any extra space.
*/

long long maxSubarraySum1(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
            start = i; // starting index

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    // if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
