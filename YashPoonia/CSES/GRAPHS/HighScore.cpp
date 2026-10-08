#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> edges;
    vector<vector<long long>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        long long u, v;
        long long w;
        cin >> u >> v >> w;
        w = -w;
        edges.push_back({u, v, w});
        graph[u].push_back(v);
    }
    vector<long long> d(n + 1, 1e18);
    d[1] = 0;
    for (long long i = 0; i < n - 1; i++)
    {
        for (auto k : edges)
        {
            long long u = k[0];
            long long v = k[1];
            long long w = k[2];

            if (d[u] != 1e18 && d[u] + w < d[v])
            {
                d[v] = d[u] + w;
            }
        }
    }
    unordered_set<long long> cycle_nodes;
    for (auto k : edges)
    {
        long long u = k[0];
        long long v = k[1];
        long long w = k[2];
        if (d[u] != 1e18 && d[u] + w < d[v])
        {
            cycle_nodes.insert(v);
        }
    }

    queue<long long> q;
    q.push(1);
    queue<long long> reacheable_cycle;
    vector<bool> visited(n + 1, false);

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (visited[curr])
            continue;
        visited[curr] = true;
        if (cycle_nodes.count(curr))
        {
            reacheable_cycle.push(curr);
        }

        for (auto neigh : graph[curr])
        {
            if (!visited[neigh])
            {
                q.push(neigh);
            }
        }
    }

    visited.assign(n + 1, false);

    while (!reacheable_cycle.empty())
    {
        auto curr = reacheable_cycle.front();
        reacheable_cycle.pop();
        if (visited[curr])
            continue;
        visited[curr] = true;
        if (curr == n)
        {
            cout << -1 << endl;
            return 0;
        }
        for (auto neigh : graph[curr])
        {
            if (!visited[neigh])
            {
                reacheable_cycle.push(neigh);
            }
        }
    }

    cout << -d[n] << endl;
}