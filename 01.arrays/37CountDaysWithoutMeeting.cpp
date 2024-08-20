#include <bits/stdc++.h>
// You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1).
// You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i
// (inclusive). Return the count of days when the employee is available for work but no meetings are scheduled.
// Note: The meetings may overlap.

// Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
// Output: 2
// Explanation:
// There is no meeting scheduled on the 4th and 8th days.

// Input: days = 5, meetings = [[2,4],[1,3]]
// Output: 1
// Explanation:
// There is no meeting scheduled on the 5th day.

// Input: days = 6, meetings = [[1,6]]
// Output: 0
// Explanation:
// Meetings are scheduled for all working days.
int countDays(int days, vector<vector<int>> &meetings)
{
    // int n = meetings.size();
    // sort(meetings.begin(), meetings.end());
    // for (int i = 0; i < n; i++) {
    //     cout << meetings[i][0] << "," << meetings[i][1] << endl;
    // }
    // int cnt = 0;
    // int last_end = meetings[0][1];
    // int first_start = meetings[0][0];
    // for (int i = 1; i < n; i++) {
    //     int gap = meetings[i][0] - last_end - 1;
    //     if (gap > 0) {
    //         cnt += gap;
    //     }
    //     last_end = max(last_end, meetings[i][1]);
    // }
    // cnt += (days - last_end) + (first_start - 1);
    // return cnt;
    sort(meetings.begin(), meetings.end());

    int strt = meetings[0][0];
    int end = meetings[0][1];

    for (int i = 1; i < meetings.size(); i++)
    {
        if (meetings[i][0] <= end)
        {
            end = std::max(end, meetings[i][1]);
        }
        else
        {
            days -= end - strt + 1;
            strt = meetings[i][0];
            end = meetings[i][1];
        }
    }
    days -= end - strt + 1;

    return days;
}