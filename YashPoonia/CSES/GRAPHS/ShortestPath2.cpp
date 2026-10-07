#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long m;
    long long q;
    cin >> n >> m >> q;

    // vector<vector<pair<int, int>>> adj;
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, LLONG_MAX));
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long d;
        cin >> u >> v >> d;
        // adj[u].push_back({d, v});
        // adj[v].push_back({d, u});
        dist[u][v] = min(dist[u][v], d);
        dist[v][u] = min(dist[v][u], d);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << (dist[u][v] == LLONG_MAX ? -1 : dist[u][v]) << endl;
    }
}
