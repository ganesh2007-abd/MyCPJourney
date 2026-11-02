#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, revadj;
vector<bool> ass, vis;
vector<int> component;
stack<int> order;

int n, m;

int negatevar(int x)
{
    return x >= m ? x - m : x + m;
}

void addclause(int x, int y)
{
    adj[negatevar(x)].push_back(y);
    adj[negatevar(y)].push_back(x);
    revadj[y].push_back(negatevar(x));
    revadj[x].push_back(negatevar(y));
}

void dfs1(int u)
{
    vis[u] = true;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs1(v);
        }
    }
    order.push(u);
}

void dfs2(int u, int comp)
{
    component[u] = comp;
    for (int v : revadj[u])
    {
        if (component[v] == -1)
        {
            dfs2(v, comp);
        }
    }
}

int main()
{
    cin >> n >> m;

    adj.resize(2 * m);
    revadj.resize(2 * m);

    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        int x, y;

        cin >> s1 >> x >> s2 >> y;

        x--;
        y--;
        if (s1 == "-")
            x = negatevar(x);
        if (s2 == "-")
            y = negatevar(y);

        addclause(x, y);
    }

    vis.resize(2 * m, false);

    for (int i = 0; i < 2 * m; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }

    component.resize(2 * m, -1);
    int comp = 0;
    while (!order.empty())
    {
        int u = order.top();
        order.pop();
        if (component[u] == -1)
        {
            dfs2(u, comp++);
        }
    }
    ass.resize(m);
    for (int i = 0; i < m; i++)
    {
        if (component[i] == component[negatevar(i)])
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        ass[i] = component[i] > component[negatevar(i)];
    }

    for (int i = 0; i < m; i++)
    {
        cout << (ass[i] ? "+ " : "- ");
    }
}