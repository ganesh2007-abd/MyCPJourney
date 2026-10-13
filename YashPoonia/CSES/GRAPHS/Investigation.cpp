#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});
    vector<vector<ll>> dp(n + 1, vector<ll>(4, INF));
    dp[1] = {0, 1, 0, 0};

    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        ll d = tmp.first;
        int u = tmp.second;

        if (d > dp[u][0])
            continue;

        for (auto temp : graph[u])
        {
            int v = temp.first;
            ll wt = temp.second;

            if (d + wt < dp[v][0])
            {
                dp[v][0] = d + wt;
                dp[v][1] = dp[u][1];
                dp[v][2] = dp[u][2] + 1;
                dp[v][3] = dp[u][3] + 1;
                pq.push({dp[v][0], v});
            }

            else if (d + wt == dp[v][0])
            {
                dp[v][1] = (dp[v][1] + dp[u][1]) % mod;
                dp[v][2] = min(dp[v][2], dp[u][2] + 1);
                dp[v][3] = max(dp[v][3], dp[u][3] + 1);
            }
        }
    }
    for (auto val : dp[n])
    {
        cout << val << " ";
    }
}