#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited)
{
    if (visited[u])
        return;
    visited[u] = true;

    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            dfs(v, graph, visited);
        }
    }
}

int main()
{

    vector<vector<int>> graph, reversed;
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    reversed.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        reversed[v].push_back(u);
    }

    dfs(1, graph, visited);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << "NO" << endl;
            cout << "1 " << i << endl;
            return 0;
        }
    }

    fill(visited.begin(), visited.end(), false);

    dfs(1, reversed, visited);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << "NO\n";
            cout << i << " 1" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}