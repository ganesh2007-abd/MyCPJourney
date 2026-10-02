#include <bits/stdc++.h>
using namespace std;

long long f(long long n, long long m)
{
    long long rem = n % m;
    return ((n / m) * (m * (m - 1) / 2)) + (rem * (rem + 1) / 2);
}

void solve()
{
    long long a, b, m;
    cin >> a >> b >> m;
    cout << f(b, m) - f(a, m) << endl;
    // long long ans = 0;
    // for (int i = a + 1; i <= b; i++)
    // {
    //     ans += i % m;
    // }
    // cout << ans << endl;
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