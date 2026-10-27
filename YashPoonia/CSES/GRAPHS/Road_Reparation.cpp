#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<bool> visited(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    long long ans = 0;
    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        int d = tmp.first;
        int u = tmp.second;
        if (visited[u])
            continue;
        visited[u] = true;
        ans += d;
        for (auto edge : graph[u])
        {
            int v = edge.first;
            int wt = edge.second;
            if (!visited[v])
            {
                pq.push({wt, v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << ans << endl;
}