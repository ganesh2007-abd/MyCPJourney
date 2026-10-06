#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long m, n;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n + 1);

    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>>
        pq;
    for (long long i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        auto x = pq.top();
        int curr = x.second;
        long long d = x.first;
        pq.pop();

        if (d > dist[curr])
            continue;

        for (auto k : adj[curr])
        {
            long long neigh = k.first;
            long long wt = k.second;

            if (dist[curr] + wt < dist[neigh])
            {
                dist[neigh] = dist[curr] + wt;
                pq.push({dist[neigh], neigh});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}