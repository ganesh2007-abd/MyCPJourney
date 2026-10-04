#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;

int cycle_start = -1;
int cycle_end;

bool dfs(int u, int par)
{
    visited[u] = true;
    for (auto neigh : adj[u])
    {
        if (neigh == par)
            continue;

        if (visited[neigh])
        {
            cycle_start = neigh;
            cycle_end = u;
            return true;
        }

        parent[neigh] = u;

        if (dfs(neigh, u))
            return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
            {
                break;
            }
        }
    }
    if (cycle_start == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> cycle;
    cycle.push_back(cycle_start);
    int curr = cycle_end;
    while (curr != cycle_start)
    {
        cycle.push_back(curr);
        curr = parent[curr];
    }
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << endl;
    for (auto num : cycle)
    {
        cout << num << " ";
    }
}