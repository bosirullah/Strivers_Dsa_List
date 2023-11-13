/*
    Reverse integer

    Problem:
    Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

*/

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(n), where n is the length of the given number
    Space Complexity: O(1)
*/

class Solution
{
public:
    int reverse(int x)
    {
        int num = abs(x);
        int res = 0;
        while (num > 0)
        {
            int rem = num % 10;
            num /= 10;

            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && rem > 7))
                return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && rem < -8))
                return 0;
            res = res * 10 + rem;
        }

        return x > 0 ? res : -res;
    }
};

int main()
{
    Solution s;

    int n = 1232132132;
    cout << s.reverse(n) << endl;
}