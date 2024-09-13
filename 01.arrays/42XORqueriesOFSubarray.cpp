#include <bits/stdc++.h>
vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    // int n = queries.size();
    // vector<int> ans(n);

    // for(int i=0;i<n;i++){
    //     int l = queries[i][0];
    //     int r = queries[i][1];
    //     int val = 0;
    //     while(l<=r){
    //         val ^= arr[l];
    //         l++;
    //     }
    //     ans[i] = val;
    // }
    // return ans;

    int m = arr.size();
    int n = queries.size();

    vector<int> ans;
    for (int i = 1; i < m; i++)
    {
        arr[i] ^= arr[i - 1];
    }

    for (auto q : queries)
    {
        if (q[0] > 0)
            ans.push_back(arr[q[1]] ^ arr[q[0] - 1]);
        else
            ans.push_back(arr[q[1]]);
    }
    return ans;
}