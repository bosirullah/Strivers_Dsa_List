/*
    Factorial of a Number : Iterative and Recursive

    Problem Statement: Given a number X,  print its factorial.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Using iteration

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

int factorial(int X)
{
    int ans = 1;
    for (int i = 1; i <= X; i++)
    {
        ans = ans * i;
    }
    return ans;
}

/*
    Solution 2: Using Recursion

    Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }
    Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
*/

int factorial(int n)
{
    // Base Condition.
    if (n == 0)
        return 1;

    // Problem broken down into 2 parts and then combined.
    return n * factorial(n - 1);
}

int main()
{
    int n = 5;
    cout << factorial(n) << endl;
}