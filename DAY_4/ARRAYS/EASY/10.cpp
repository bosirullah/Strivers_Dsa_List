/*
    Find the missing number in an array

    Problem Statement:
    Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N),
    that is not present in the given array.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Using Brute force approach

    Naive Approach(Brute-force approach):
    Intuition:
    For each number between 1 to N, we will try to find it in the given array using linear search. And if we don’t find any
    of them, we will return the number.

    Time Complexity: O(N2), where N = size of the array+1.
    Reason:
    In the worst case i.e. if the missing number is N itself, the outer loop will run for N times, and for every
    single number the inner loop will also run for approximately N times. So, the total time complexity will be O(N2).

    Space Complexity: O(1)  as we are not using any extra space.
*/

int missingNumber(vector<int> &a, int N)
{
    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N; i++)
    {
        // flag variable to check
        // if an element exists
        int flag = 0;

        // Search the element using linear search:
        for (int j = 0; j < N - 1; j++)
        {
            if (a[j] == i)
            {
                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        // i.e flag == 0:
        if (flag == 0)
            return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}

/*
    Solution 2: Using hashing

    Better Approach (using Hashing):
    Intuition:
    Using the hashing technique, we will store the frequency of each element of the given array. Now, the
    number( i.e. between 1 to N) for which the frequency will be 0, will be returned. Refer to the article link to
    know more about hashing.

    Time Complexity: O(N) + O(N) ~ O(2*N),  where N = size of the array+1.
    Reason:
    For storing the frequencies in the hash array, the program takes O(N) time complexity and for checking the frequencies
    in the second step again O(N) is required. So, the total time complexity is O(N) + O(N).

    Space Complexity: O(N), where N = size of the array+1. Here we are using an extra hash array of size N+1.
*/

int missingNumber(vector<int> &a, int N)
{
    vector<int> hash(N + 1, 0); // hash array

    // storing the frequencies:
    for (int i = 0; i < N; i++)
    {
        hash[a[i]]++;
    }

    // checking the freqencies for numbers 1 to N:
    for (int i = 0; i <= N; i++)
    {
        if (hash[i] == 0)
            return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}

/*
    Solution 3: Using Summation approach

    Intuition:
    We know that the summation of the first N numbers is (N*(N+1))/2. We can say this S1. Now, in the given array,
    every number between 1 to N except one number is present. So, if we add the numbers of the array (say S2), the
    difference between S1 and S2 will be the missing number. Because, while adding all the numbers of the array, we did
    not add that particular number that is missing.

    Time Complexity: O(N), where N = size of array+1.
    Reason:
    Here, we need only 1 loop to get the sum of the array elements. The loop runs for approx. N times. So, the time
    complexity is O(N).

    Space Complexity: O(1) as we are not using any extra space.
*/

int missingNumber(vector<int> &a, int N)
{
    // Summation of first N numbers:
    int tot_sum = (N * (N + 1)) / 2;
    // Summation of all array elements:
    int curr_sum = 0;
    for (int x : a)
    {
        curr_sum += x;
    }

    int missingNum = tot_sum - curr_sum;

    return missingNum;
}

/*
    Solution 4: Using XOR approach

    Intuition:
    Two important properties of XOR are the following:

    XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
    XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

    Now, let’s XOR all the numbers between 1 to N.
    xor1 = 1^2^…….^N

    Let’s XOR all the numbers in the given array.
    xor2 = 1^2^……^N (contains all the numbers except the missing one).

    Now, if we again perform XOR between xor1 and xor2, we will get:
    xor1 ^ xor2 = (1^1)^(2^2)^……..^(missing Number)^…..^(N^N)

    Here all the numbers except the missing number will form a pair and each pair will result in 0 according to the XOR property. The result will be = 0 ^ (missing number) = missing number (according to property 2).

    So, if we perform the XOR of the numbers 1 to N with the XOR of the array elements, we will be left with the missing number.

    Time Complexity: O(N), where N = size of array+1.
    Reason:
    Here, we need only 1 loop to calculate the XOR. The loop runs for approx. N times. So, the time complexity is O(N).

    Space Complexity: O(1) as we are not using any extra space.
*/

int missingNumber(vector<int> &a, int N)
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        res ^= i;    // XOR of 0 to n-1 elements
        res ^= a[i]; // XOR of array elements
    }

    res ^= N; // XOR upto 0 to N

    return res; // the missing number
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}