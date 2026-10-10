#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    vector<vector<ll>> dist(n + 1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        ll d = tmp.first;
        int u = tmp.second;
        if (dist[u].size() >= k)
            continue;
        dist[u].push_back(d);
        for (auto p : graph[u])
        {
            ll wt = p.second;
            int v = p.first;
            ll newdist = d + wt;
            pq.push({newdist, v});
        }
    }
    // cout << "loop done" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << dist[n][i] << " ";
    }
}