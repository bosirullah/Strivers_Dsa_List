/*
    Check if a number is prime or not

    Problem Statement:
    Given a number, check whether it is prime or not. A prime number is a natural number that is only divisible by 1 and by itself.

*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Brute force approach

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

bool isPrime(int N)
{
    for (int i = 2; i < N; i++)
    {
        if (N % i == 0)
        {
            return false;
        }
    }
    return true;
}

/*
    Solution 2: Optimal approach

    Time Complexity: O(sqrt(n))
    Space Complexity: O(1)
*/

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n = 11;
    cout << isPrime(n) << endl;
}