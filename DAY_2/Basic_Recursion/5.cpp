/*
    Sum of first N Natural Numbers

    Problem statement: Given a number ‘N’, find out the sum of the first N natural numbers.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution1: Using Loop

    Time Complexity: O(N)
    Space Complexity: O(1)
*/

void solve(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "The sum of the first " << n << " numbers is: " << sum << endl;
}

/*
    Solution 2: Using the formula

    Time Complexity: O(1)
    Space Complexity: O(1)
*/

void solve(int N)
{
    int sum = N * (N + 1) / 2;
    cout << "The sum of the first " << N << " numbers is: " << sum << endl;
}

/*
    Solution 3: Using recursion
    Recursive way of calculating the sum of first N Natural Numbers:
        i) Parameterized Way
        ii) Functional Way
*/

/*
    i) Parameterized Way

    Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }
    Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
*/

void func(int i, int sum)
{
    // Base Condition.
    if (i < 1)
    {
        cout << sum << endl;
        return;
    }
    // Function call to increment sum by i till i decrements to 1.
    func(i - 1, sum + i);
}

/*
    ii) Functional Way

    Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }
    Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
*/

int func(int n)
{
    // Base Condition.
    if (n == 0)
    {
        return 0;
    }
    // Problem broken down into 2 parts and then combined.
    return n + func(n - 1);
}

int main()
{
    int n = 5;
    func(1, n);
    // solve(n);
}