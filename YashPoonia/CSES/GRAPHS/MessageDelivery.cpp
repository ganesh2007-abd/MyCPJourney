#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool found = false;

    queue<int> q;
    q.push(1);

    while (!q.empty() && !found)
    {
        int curr = q.front();
        q.pop();
        for (auto neigh : adj[curr])
        {
            if (!visited[neigh])
            {
                visited[neigh] = true;
                q.push(neigh);
                parent[neigh] = curr;
            }
            if (neigh == n)
            {
                found = true;
                break;
            }
        }
    }

    if (!visited[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> path;
    int curr = n;
    while (curr != 1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(1);
    cout << path.size() << endl;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
}