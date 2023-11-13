/*
    Print all Divisors of a given Number

    Problem Statement:
    Given a number, print all the divisors of the number. A divisor is a number that gives the remainder as zero when divided.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Brute force Approach

    Time Complexity: O(n), because the loop has to run from 1 to n always.
    Space Complexity: O(1), we are not using any extra space.

*/

void printDivisorsBruteForce(int n)
{

    cout << "The Divisors of " << n << " are:" << endl;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            cout << i << " ";

    cout << "\n";
}

/*
    Solution 2: Optimal Approach

    Time Complexity: O(sqrt(n)), because every time the loop runs only sqrt(n) times.
    Space Complexity: O(1), we are not using any extra space.

*/

void printDivisorsOptimal(int n)
{

    cout << "The Divisors of " << n << " are:" << endl;
    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i)
                cout << n / i << " ";
        }

    cout << "\n";
}

int main()
{
    printDivisorsBruteForce(36);
}