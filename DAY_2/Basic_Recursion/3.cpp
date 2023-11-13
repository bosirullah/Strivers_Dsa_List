/*
    Print 1 to N using Recursion

    Problem: Print from 1 to N using Recursion
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }
    Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
*/

void helper(int i, int x, vector<int> &res)
{
    if (i > x)
        return;
    res.push_back(i);

    helper(i + 1, x, res);
}

vector<int> printNos(int x)
{
    vector<int> res;
    helper(1, x, res);

    return res;
}

int main()
{
    int n = 5;
    vector<int> res;
    res = printNos(n);

    for (auto x : res)
    {
        cout << x << " ";
    }
}