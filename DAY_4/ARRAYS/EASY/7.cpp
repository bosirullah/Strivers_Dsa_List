/*
    Move all Zeros to the end of the array

    Problem Statement:
    You are given an array of integers, your task is to move all the zeros in the array to the end of
    the array and move non-negative integers to the front by maintaining their order.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Using brute force
    The extremely naive solution, we can think of, involves the use of an extra array. The algorithm is as follows.

    Time Complexity: O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. of elements,
    X = no. of non-zero elements, and N-X = total no. of zeros.

    Reason:
    O(N) for copying non-zero elements from the original to the temporary array. O(X) for again copying it back from
    the temporary to the original array. O(N-X) for filling zeros in the original array. So, the total time complexity
    will be O(2*N).

    Space Complexity: O(N), as we are using a temporary array to solve this problem and the maximum size of the array
    can be N in the worst case.

    Reason: The temporary array stores the non-zero elements. In the worst case, all the given array elements will be
    non-zero.
*/

vector<int> moveZeros(int n, vector<int> a)
{
    // temporary array:
    vector<int> temp;
    // copy non-zero elements
    // from original -> temp array:
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }

    // number of non-zero elements.
    int nz = temp.size();

    // copy elements from temp
    // fill first nz fields of
    // original array:
    for (int i = 0; i < nz; i++)
    {
        a[i] = temp[i];
    }

    // fill rest of the cells with 0:
    for (int i = nz; i < n; i++)
    {
        a[i] = 0;
    }
    return a;
}

/*
    Solution 3: Optimal Approach(Using 2 pointers)

    Time Complexity: O(N), N = size of the array.
    Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/

vector<int> moveZeros(int n, vector<int> a)
{
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        // put i at the index where element is 0
        while (i < n && (a[i] != 0))
            i++;

        // put j at the index where element is non-zero and is after the ith index
        while (j < n && (a[j] == 0 || i > j))
            j++;

        // if no such elements are found for i and j then break out of the loop
        if (i >= n || j >= n)
            break;

        swap(a[i++], a[j++]);
    }

    return a;
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}
