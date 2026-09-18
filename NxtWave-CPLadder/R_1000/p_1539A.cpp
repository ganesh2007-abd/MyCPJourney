#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x, t;
    cin >> n >> x >> t;
    long long ans = 0;
    long long dpp = min(n - 1, t / x);
    ans += dpp * (n - dpp);
    ans += dpp * (dpp - 1) / 2;
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