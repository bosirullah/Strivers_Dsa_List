/*
    Palindrome Number

    Problem:
    Given an integer x, return true if x is a palindrome, and false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N)  , where N is number of digits
    Space Complexity: O(N)
*/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string str = to_string(x);
        string s = to_string(x);

        reverse(s.begin(), s.end());

        return str == s ? true : false;
    }
};

/*
    Time complexity: O(log(N))  for reversing N digits of input integer.
    Space complexity: O(1)
*/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int num = x;
        long rev = 0;
        while (num > 0)
        {
            rev = rev * 10 + num % 10;
            num /= 10;
        }

        return rev == x ? true : false;
    }
};

int main()
{
    int n = 127;
    Solution s;
    cout << s.isPalindrome(n) << endl;
}