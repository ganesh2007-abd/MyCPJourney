#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, l, d;
    cin >> n >> l >> d;
    vector<long long> bagpos;
    for (long long i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        bagpos.push_back(temp);
    }

    long long ans = ((d / l) * n);

    if ((d / l) % 2 == 0)
    {
        long long currpos = d % l;
        // cout << ans << " " << currpos << endl;
        for (long long num : bagpos)
        {
            ans += (num <= currpos);
        }
    }
    else if ((d / l) % 2 != 0)
    {
        long long currpos = l - d % l;

        // cout << ans << " " << currpos << endl;
        for (long long num : bagpos)
        {
            ans += (num >= currpos);
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}