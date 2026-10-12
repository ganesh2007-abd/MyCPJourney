#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
long long mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
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
            }
        }
    }

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int u : order)
    {
        for (int v : graph[u])
        {
            dp[v] = (dp[v] + dp[u]) % mod;
        }
    }

    cout << dp[n] << endl;
}