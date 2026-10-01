#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
int n, m;

void dfs(int i)
{
    visited[i] = true;

    for (auto v : adj[i])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    cin >> n >> m;
    visited.assign(n + 1, false);
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int s, d;
        cin >> s >> d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    int count = 0;
    vector<int> startingpos;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            startingpos.push_back(i);
            dfs(i);
            count++;
        }
    }
    cout << count - 1 << endl;
    for (int i = 1; i < startingpos.size(); i++)
    {
        cout << startingpos[i] << " " << startingpos[i - 1] << endl;
    }
}