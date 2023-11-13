/*
    Find GCD of two numbers

    Problem Statement: Find the gcd of two numbers.

*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: brute force approach

    Time complexity: O(min(n,m))
    Space complexity: O(1)
*/

int calcGCD(int n, int m)
{
    int gcd = 1;

    int size = n > m ? m : n;

    for (int i = 1; i <= size; i++)
    {
        if (m % i == 0 && n % i == 0)
        {
            gcd = i;
        }
    }

    return gcd;
}

/*
    Solution 2: Using Euclidean algorithm
    Intuition: Gcd is the greatest number which is divided by both a and b.If a number is divided by both a and b, it is should be divided by (a-b) and b as well.

    Approach:
    Recursively call gcd(b,a%b) function till the base condition is hit.
    b==0 is the base condition.When base condition is hit return a,as gcd(a,0) is equal to a.

    Time Complexity: O(log(min(n,m)))  phi is the base where phi = 1.61
    Space Complexity: O(1)

*/

int calcGCD(int n, int m)
{
    if (m == 0)
        return n;

    return calcGCD(m, n % m);
}

int main()
{
    int n = 4, m = 9;

    cout << calcGCD(n, m) << endl;
}