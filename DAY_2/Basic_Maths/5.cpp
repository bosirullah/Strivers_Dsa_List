/*
    Check if a number is Armstrong Number or not

    Problem Statement:
    Given a number, check if it is Armstrong Number or Not.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(n) where n is the number of digits since we need to traverse every digit and add digits raised to power no. of digits to sum.
    Space Complexity: O(1) since no extra space is required
*/

int countDigits(int n)
{
    string x = to_string(n);
    return x.length();
}

bool checkArmstrong(int n)
{
    int digitsCount = countDigits(n);
    int num = n;
    int res = 0;
    while (num > 0)
    {
        int rem = num % 10;
        res += pow(rem, digitsCount);
        num /= 10;
    }

    return (res == n);
}

int main()
{
    int n = 153;
    cout << checkArmstrong(n) << endl;
}