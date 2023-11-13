/*
    Check if the given String is Palindrome or not

    Problem Statement:
    “Given a string, check if the string is palindrome or not.”  A string is said to be palindrome
    if the reverse of the string is the same as the string.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Using Recursion

    Time Complexity: O(N) { Precisely, O(N/2) as we compare the elements N/2 times and swap them}.
    Space Complexity: O(1) { The elements of the given array are swapped in place so no extra space is required}.
*/

bool helper(int i, int n, string &str)
{
    // Base Condition
    // If i exceeds half of the string means all the elements
    // are compared, we return true.
    if (i >= n / 2)
        return true;

    // If the start is not equal to the end, not the palindrome.
    if (str[i] != str[n - i - 1])
        return false;

    // If both characters are the same, increment i and check start+1 and end-1.
    return helper(i + 1, n, str);
}

bool isPalindrome(string &str)
{
    int n = str.size();
    return helper(0, n, str);
}

int main()
{
    string str = "ala";
    cout << isPalindrome(str) << endl;
}