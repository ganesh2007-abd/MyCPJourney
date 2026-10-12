#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> parent;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    parent.assign(n + 1, -1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty())
    {
        int u = q.front();
        order.push_back(u);
        q.pop();
        for (int v : graph[u])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {

                q.push(v);
                order.push_back(v);
            }
        }
    }

    vector<int> dp(n + 1, INT_MIN);
    dp[1] = 1;
    for (int u : order)
    {
        if (dp[u] == INT_MIN)
            continue;
        for (int v : graph[u])
        {
            if (dp[u] + 1 > dp[v])
            {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }
    if (dp[n] == INT_MIN)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << dp[n] << endl;
    vector<int> path;
    for (int curr = n; curr != -1; curr = parent[curr])
    {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());
    for (auto node : path)
    {
        cout << node << " ";
    }
}