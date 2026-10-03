#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> team;

bool bfs(int start)
{
    queue<int> q;
    q.push(start);
    team[start] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto neigh : graph[node])
        {
            if (team[neigh] == -1)
            {
                team[neigh] = 3 - team[node];
                q.push(neigh);
            }
            if (team[neigh] == team[node])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    team.assign(n + 1, -1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (team[i] == -1)
        {
            bool res = bfs(i);
            if (res == false)
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << team[i] << " ";
    }
}