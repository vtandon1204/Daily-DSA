#include <bits/stdc++.h>
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations
// in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Input: candidates = [2,5,2,1,2], target = 5
// Output:
// [
// [1,2,2],
// [5]
// ]
void func(int index, int target, vector<int> &candidates, vector<int> &temp,
          vector<vector<int>> &ans)
{
    int n = candidates.size();
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = index; i < n; i++)
    {
        if (candidates[i] > target)
        {
            break;
        }
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        temp.push_back(candidates[i]);
        func(i + 1, target - candidates[i], candidates, temp, ans);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
sort(candidates.begin(), candidates.end());
    func(0, target, candidates, temp, ans);
    return ans;
}