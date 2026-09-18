#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x, t;
    cin >> n >> x >> t;
    if (t < x)
    {
        cout << '0' << endl;
        return;
    }
    else if (t == x)
    {
        cout << '1' << endl;
        return;
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        ans += min((n - i), t / x);
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