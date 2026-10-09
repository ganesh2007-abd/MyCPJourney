#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
    }
    vector<vector<ll>> dist(n + 1, vector<ll>(2, LLONG_MAX));
    dist[1][0] = 0;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;
    pq.push({0, 1, 0});

    while (!pq.empty())
    {

        ll currdist = get<0>(pq.top());
        ll node = get<1>(pq.top());
        ll used = get<2>(pq.top());
        pq.pop();

        if (currdist > dist[node][used])
            continue;

        for (auto temp : graph[node])
        {
            auto nbr = temp.first;
            auto w = temp.second;
            if (used == 0)
            {
                if (currdist + w < dist[nbr][0])
                {
                    dist[nbr][0] = currdist + w;
                    pq.push({dist[nbr][0], nbr, 0});
                }
                if (currdist + w / 2 < dist[nbr][1])
                {
                    dist[nbr][1] = currdist + w / 2;
                    pq.push({dist[nbr][1], nbr, 1});
                }
            }
            else
            {
                if (currdist + w < dist[nbr][1])
                {
                    dist[nbr][1] = currdist + w;
                    pq.push({dist[nbr][1], nbr, 1});
                }
            }
        }
    }

    cout << dist[n][1] << endl;
}