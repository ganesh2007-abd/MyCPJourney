#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> reversedgraph;
vector<bool> visited;
stack<int> finishorder;

void dfs(int u)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
    finishorder.push(u);
}

void dfsr(int u, vector<int> &comp)
{
    visited[u] = true;
    comp.push_back(u);
    for (auto v : reversedgraph[u])
    {
        if (!visited[v])
        {
            dfsr(v, comp);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    reversedgraph.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        reversedgraph[v].push_back(u);
    }

    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    fill(visited.begin(), visited.end(), false);
    vector<int> kingdom(n + 1, 0);
    int currlabel = 1;
    while (!finishorder.empty())
    {
        int curr = finishorder.top();
        finishorder.pop();
        if (!visited[curr])
        {
            vector<int> component;
            dfsr(curr, component);
            for (auto node : component)
            {
                kingdom[node] = currlabel;
            }
            currlabel++;
        }
    }
    cout << currlabel - 1 << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << kingdom[i] << " ";
    }
}