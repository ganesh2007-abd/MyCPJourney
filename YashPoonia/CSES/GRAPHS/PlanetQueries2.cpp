#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>> up;
vector<bool> visited;
vector<int> len;
vector<int> parent;

void dfs(int node)
{
    if (visited[node])
        return;
    visited[node] = true;

    dfs(parent[node]);

    up[0][node] = parent[node];

    len[node] = len[up[0][node]] + 1;
    for (int j = 1; j < LOG; j++)
    {
        up[j][node] = up[j - 1][up[j - 1][node]];
    }
}

int jump(int a, int k)
{
    if (k < 0)
        return -1;
    for (int i = 0; k > 0; i++, k >>= 1)
    {
        if ((k & 1))
        {
            a = up[i][a];
        }
    }
    return a;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    up.assign(LOG, vector<int>(n + 1));
    visited.assign(n + 1, false);
    len.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> parent[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        int ans;

        int entry = jump(a, len[a]);

        if (len[a] < len[b] && entry == b)
            ans = len[a];

        if (jump(a, len[a] - len[b]) == b)
        {
            ans = len[a] - len[b];
        }

        else if (jump(entry, len[entry] - len[b]) == b)
        {
            ans = len[a] + (len[entry] - len[b]);
        }

        else
        {
            ans = -1;
        }

        cout << ans << '\n';
    }
}