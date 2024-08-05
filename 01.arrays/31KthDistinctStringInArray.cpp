#include <bits/stdc++.h>
// A distinct string is a string that is present only once in an array.
// Given an array of strings arr, and an integer k, return the kth distinct string present in arr. 
// If there are fewer than k distinct strings, return an empty string "".
// Note that the strings are considered in the order in which they appear in the array.

// Input: arr = ["d","b","c","b","c","a"], k = 2
// Output: "a"
// Explanation:
// The only distinct strings in arr are "d" and "a".
// "d" appears 1st, so it is the 1st distinct string.
// "a" appears 2nd, so it is the 2nd distinct string.
// Since k == 2, "a" is returned. 

// Input: arr = ["aaa","aa","a"], k = 1
// Output: "aaa"
// Explanation:
// All strings in arr are distinct, so the 1st string "aaa" is returned.

// Input: arr = ["a","b","a"], k = 3
// Output: ""
// Explanation:
// The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
string kthDistinct(vector<string> &arr, int k)
{
    unordered_map<string, int> freq;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        freq[arr[i]]++;
    }
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (freq[arr[i]] == 1)
        {
            cnt++;
            if (cnt == k)
            {
                return arr[i];
            }
        }
    }
    return "";
}