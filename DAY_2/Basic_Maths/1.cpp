/*
    Count digits in a number

    Problem Statement: Given an integer N, write a program to count the number of digits in N.

*/

#include <bits/stdc++.h>
using namespace std;

/*
    SOLUTION 1:

    Complexity Analysis
        Time Complexity: O(n) where n is the number of digits in the given integer
        Space Complexity: O(1)
*/

int countDigits(int n)
{
    int count = 0;
    int num = n;
    while (num > 0)
    {
        num /= 10;
        count++;
    }

    return count;
}

/*
    SOLUTION 2:

    Complexity Analysis
        Time Complexity: O(1)
        Space Complexity: O(1)
*/

int countDigits(int n)
{
    string num = to_string(n);
    return num.length();
}

/*
    SOLUTION 3:

    Complexity Analysis
        Time Complexity: O(1)
        Space Complexity: O(1)
*/

int countDigits(int n)
{
    int digits = floor(log10(n) + 1);
    return digits;
}

int main()
{
    int n = 12345;
    cout << countDigits(n) << endl;
}