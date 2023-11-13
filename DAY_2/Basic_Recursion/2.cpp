/*
    Print Name N times using Recursion
    Problem: Print your Name N times using recursion
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }
    Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
*/

void helper(int n, vector<string> &res)
{
    if (n == 0)
        return;
    res.push_back("Coding Ninjas");

    helper(n - 1, res);
}

vector<string> printNTimes(int n)
{
    vector<string> res;
    helper(n, res);

    return res;
}

int main()
{
    int n = 5;
    vector<string> res;
    res = printNTimes(n);

    for (auto x : res)
    {
        cout << x << " ";
    }
}