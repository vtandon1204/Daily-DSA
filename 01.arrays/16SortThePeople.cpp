#include <bits/stdc++.h>
// You are given an array of strings names, and an array heights that consists of distinct positive integers.
// Both arrays are of length n.
// For each index i, names[i] and heights[i] denote the name and height of the ith person.
// Return names sorted in descending order by the people's heights.

// Input: names = ["Mary","John","Emma"], heights = [180,165,170]
// Output: ["Mary","Emma","John"]
// Explanation: Mary is the tallest, followed by Emma and John.

// Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
// Output: ["Bob","Alice","Bob"]
// Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{
    int n = heights.size();
    vector<string> ans;
    vector<pair<int, string>> data(n);
    for (int i = 0; i < n; i++)
    {
        data[i] = {heights[i], names[i]};
    }
    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());
    for (int i = 0; i < n; i++)
    {
        ans.push_back(data[i].second);
    }
    return ans;
}