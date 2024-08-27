#include <bits/stdc++.h>
int findCenter(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;
    // vector<int> visited(n+1,0);
    bitset<100000> visited = 0;
    for (auto &e : edges)
    {
        int v = e[0], w = e[1];
        if (visited[v])
            return v;
        if (visited[w])
            return w;
        visited[v] = visited[w] = 1;
    }
    return -1;
}