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

    Intuition:
    We will check the sum of every possible subarray and consider the maximum among them. To get every possible subarray sum, we will be using three nested loops.
    The first loops(say i and j) will iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will
    be from index i to index j. Using another loop we will get the sum of the elements of the subarray [i…..j]. Among all values of the sum calculated, 
    we will consider the maximum one.

    Note: We are selecting every possible subarray using two nested loops and for each of them, we add all its elements using another loop.

    Time Complexity: O(N3), where N = size of the array.
    Reason:
    We are using three nested loops, each running approximately N times.

    Space Complexity: O(1) as we are not using any extra space.
*/

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

/*
    Solution 2: Better approach

    Algorithm / Intuition
    Intuition: 
    If we carefully observe, we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous
    subarray i.e. arr[i….j-1].

    Assume previous subarray = arr[i……j-1]
    current subarray = arr[i…..j]
    Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]

    This is how we can remove the third loop and while moving j pointer, we can calculate the sum.

    Time Complexity: O(N2), where N = size of the array.
    Reason:
    We are using two nested loops, each running approximately N times.

    Space Complexity: O(1) as we are not using any extra space.
*/

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

/*
    Solution 3: Optimal approach

    Intuition:
    The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always
    reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.

    Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes
    less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum
    one.

    Thus we can solve this problem with a single loop.

    Note: 
    In some cases, the question might say to consider the sum of the empty subarray while solving this problem. So, in these cases, before returning the answer
    we will compare the maximum subarray sum calculated with 0(i.e. The sum of an empty subarray is 0). And after that, we will return the maximum one.
    For e.g. if the given array is {-1, -4, -5}, the answer will be 0 instead of -1 in this case. 

    This is applicable to all the approaches discussed above.

    But if this case is not explicitly mentioned we will not consider this case.

    Time Complexity: O(N), where N = size of the array.
    Reason: 
    We are using a single loop running N times.

    Space Complexity: O(1) as we are not using any extra space.
*/

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}


int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int maxSum = maxSubarraySum(arr, n);
    long long maxSum = maxSubarraySum(arr,n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
