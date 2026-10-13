#include <bits/stdc++.h>
using namespace std;
const int LOG = 30;
vector<vector<int>> up;

void build(vector<int> &parent)
{
    int n = parent.size();
    up.assign(LOG, vector<int>(n));

    for (int j = 0; j < n; j++)
    {
        up[0][j] = parent[j];
    }

    for (int i = 1; i < LOG; i++)
    {
        for (int j = 0; j < n; j++)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
}

int query(int start, long long k)
{
    int curr = start;
    for (int i = 0; k > 0; i++, k >>= 1)
    {
        if (k & 1)
        {
            curr = up[i][curr];
        }
    }
    return curr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];
        parent[i]--;
    }
    // cout << "BEFORE BUILD" << endl;
    build(parent);
    // cout << "AFTER BUILD" << endl;
    for (int i = 0; i < q; i++)
    {
        int s;
        long long k;
        cin >> s >> k;
        s--;
        cout << query(s, k) + 1 << '\n';
    }
}