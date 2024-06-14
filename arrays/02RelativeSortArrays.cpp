// Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
// Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.
// Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

// Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// Output: [2,2,2,1,4,3,3,9,6,7,19]

#include <bits/stdc++.h>
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    map<int, int> mpp;
    for (int i = 0; i < arr1.size(); i++)
    {
        mpp[arr1[i]]++;
    }
    int index = 0;
    for (int i = 0; i < arr2.size(); i++)
    {
        while (mpp[arr2[i]] > 0)
        {
            arr1[index] = arr2[i];
            index++;
            mpp[arr2[i]]--;
        }
    }
    for (auto it : mpp)
    {
        while (it.second > 0)
        {
            arr1[index] = it.first;
            index++;
            it.second--;
        }
    }
    return arr1;
}