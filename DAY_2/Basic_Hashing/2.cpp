/*
    Count frequency of each element in the array

    Problem statement:
    Given an array, we have found the number of occurrences of each element in the array.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Use of two loops

    Time Complexity: O(N*N)
    Space Complexity:  O(N)
*/

void countFreq(int arr[], int n)
{
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        // Skip this element if already processed
        if (visited[i] == true)
            continue;

        // Count frequency
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}

/*
    Solution 2: Using map

    Time Complexity: O(N)
    Space Complexity:  O(N)
*/

void Frequency(int arr[], int n)
{
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    // Traverse through map and print frequencies
    for (auto x : map)
        cout << x.first << " " << x.second << endl;
}

int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
}