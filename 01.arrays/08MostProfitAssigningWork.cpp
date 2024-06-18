// You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
// difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
// worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
// Every worker can be assigned at most one job, but one job can be completed multiple times.
// For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
// Return the maximum profit we can achieve after assigning the workers to the jobs.

// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// Output: 100
// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.

// Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
// Output: 0

#include <bits/stdc++.h>
int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    sort(worker.begin(), worker.end());
    vector<pair<int, int>> pair(worker.size());
    for (int i = 0; i < worker.size(); i++)
    {
        pair[i] = {difficulty[i], profit[i]};
    }
    sort(pair.begin(), pair.end());
    int totalProfit = 0;
    int temp = 0;
    int j = 0;
    for (int i = 0; i < worker.size(); i++)
    {
        while (j < worker.size() && pair[j].first <= worker[i])
        {
            temp = max(temp, pair[j].second);
            j++;
        }
        totalProfit += temp;
    }
    return totalProfit;
}