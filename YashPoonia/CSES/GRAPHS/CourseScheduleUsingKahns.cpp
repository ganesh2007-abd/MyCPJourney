#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
queue<int> q;
vector<int> indeg;

int main()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    indeg.assign(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indeg[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for (int v : graph[curr])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
    if (ans.size() == n)
    {
        for (int node : ans)
        {
            cout << node << " ";
        }
        cout << endl;
        return 0;
    }
    cout << "IMPOSSIBLE" << endl;
}