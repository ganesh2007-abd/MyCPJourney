#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> tracker;
stack<int> order;

bool dfs(int u)
{
    visited[u] = true;
    tracker[u] = true;

    for (int v : graph[u])
    {
        if (!visited[v])
        {
            if (!dfs(v))
            {
                return false;
            }
        }
        else if (tracker[v])
        {
            return false;
        }
    }
    order.push(u);
    tracker[u] = false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.assign(n + 1, false);
    tracker.assign(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int u = 1; u <= n; u++)
    {
        if (!visited[u])
        {
            if (!dfs(u))
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    while (!order.empty())
    {
        cout << order.top() << " ";
        order.pop();
    }
}