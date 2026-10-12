#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> parent;
vector<bool> tracker;
vector<bool> visited;

int cyclestart = -1;
int cycleend = -1;

bool dfs(int u)
{
    visited[u] = true;
    tracker[u] = true;

    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            if (dfs(v))
                return true;
        }
        else if (tracker[v])
        {
            cyclestart = u;
            cycleend = v;
            return true;
        }
    }

    tracker[u] = false;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    parent.assign(n + 1, -1);
    tracker.assign(n + 1, false);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int u = 1; u <= n; u++)
    {
        if (!visited[u] && dfs(u))
        {
            break;
        }
    }

    if (cyclestart == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(cycleend);
    for (int v = cyclestart; v != cycleend; v = parent[v])
    {
        cycle.push_back(v);
    }
    cycle.push_back(cycleend);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << endl;
    for (int node : cycle)
    {
        cout << node << " ";
    }
}