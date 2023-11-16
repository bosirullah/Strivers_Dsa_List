/*
    Union of Two Sorted Arrays

    Problem Statement:
    Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

    The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Solution 1: Using Map

    Our aim is to find the common elements in arr1 and arr2, and the distinct elements of arr1,arr2. Use a Single map to
    find the frequencies of elements in arr1 and arr2.
    As we are using only a single map the common element in arr1 and arr2 are treated as a single element for finding
    frequency, so there would be no duplicates.

    Why not unordered_map?
    In unordered_map the keys are stored in random order, while in the map the keys are stored in sorted order
    (ascending order by default). As we require elements of the union to be in ascending order, using a map is preferable.

    We can also use unordered_map, but after finding the union of arr1 and arr2, we need to sort the union vector to get
    the elements of the union in sorted order.

    Time Compleixty : O( (m+n)log(m+n) ) .
    Inserting a key in map takes logN times, where N is no of elements in map. At max map can store m+n elements
    {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n)
    time. Upon approximation across insertion of all elements in worst it would take O((m+n)log(m+n) time.

    Using HashMap also takes the same time, On average insertion in unordered_map takes O(1) time but sorting the union
    vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

    Space Complexity : O(m+n) {If Space of Union ArrayList is considered}
    O(1) {If Space of union ArrayList is not considered}
*/

// vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
// {
//     map<int, int> freq;
//     vector<int> Union;

//     for (int i = 0; i < n; i++)
//         freq[arr1[i]]++;
//     for (int i = 0; i < m; i++)
//         freq[arr2[i]]++;

//     for (auto it : freq)
//     {
//         Union.push_back(it.first);
//     }

//     return Union;
// }

/*
    Solution 2: Using Set
    Suppose we consider arr1 and arr2 as a single array say arr, then the union of arr1 and arr2 is the distinct elements
    in arr.

    Time Compleixty : O( (m+n)log(m+n) ) .
    Inserting an element in a set takes logN time, where N is no of elements in the set. At max set can store m+n elements
    {when there are no common elements and elements in arr,arr2 are distntict}.So Inserting m+n th element takes log(m+n)
     time. Upon approximation across inserting all elements in worst, it would take O((m+n)log(m+n) time.

    Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but sorting the union
    vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

    Space Complexity : O(m+n) {If Space of Union ArrayList is considered}
    O(1) {If Space of union ArrayList is not considered}
*/

// vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
// {
//     set<int> s;
//     vector<int> Union;
//     for (int i = 0; i < n; i++)
//         s.insert(arr1[i]);
//     for (int i = 0; i < m; i++)
//         s.insert(arr2[i]);
//     for (auto &it : s)
//         Union.push_back(it);
//     return Union;
// }

/*
    Solution 3: Two Pointers
    Solution 1 and 2 work for the unsorted arrays also, The arrays arr1 and arr2 are sorted, can we use this property to reduce the time Complexity?

    Using the property that the arrays are sorted we can bring down the time complexity from

    O((m+n)log(m+n))    TO    O(m+n).


    Time Complexity: O(m+n),
    Because at max i runs for n times and j runs for m times. When there are no common elements in arr1 and arr2
    and all elements in arr1, arr2 are distinct.

    Space Complexity : O(m+n) {If Space of Union ArrayList is considered}
    O(1) {If Space of union ArrayList is not considered}
*/

vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> res;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (res.size() == 0 || res.back() != arr1[i])
            {
                res.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (res.size() == 0 || res.back() != arr2[j])
            {
                res.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (res.size() == 0 || res.back() != arr1[i])
        {
            res.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (res.size() == 0 || res.back() != arr2[j])
        {
            res.push_back(arr2[j]);
        }
        j++;
    }

    return res;
}

int main()
{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 6};
    int arr2[] = {2, 3, 5};

    vector<int> Union = FindUnion(arr1, arr2, n, m);

    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}