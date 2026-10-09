#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(m, vector<ll>(3));
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        ll wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    vector<ll> dist(n + 1, 0); // we do this because as the graph may contain disconnected components
    vector<ll> relaxant(n + 1, -1);
    int x = -1;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                relaxant[v] = u;
                x = v;
            }
        }
    }
    if (x == -1)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        x = relaxant[x];
    }
    vector<int> cycle;
    for (int curr = x;; curr = relaxant[curr])
    {
        cycle.push_back(curr);
        if (curr == x && cycle.size() > 1)
        {
            break;
        }
    }
    reverse(cycle.begin(), cycle.end());
    cout << "YES" << endl;
    for (auto node : cycle)
    {
        cout << node << " ";
    }
}