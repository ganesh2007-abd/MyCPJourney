#include <bits/stdc++.h>
using namespace std;

bool check(int n, long long k, long long target, vector<long long> &a, vector<long long> &b, vector<long long> &c)
{
    long long totops = 0;
    for (int i = 0; i < n; i++)
    {
        long long ops = 0;
        long long sum = a[i] + b[i] + c[i];
        if (sum >= target)
        {
            continue;
        }
        if (a[i] == b[i] && b[i] == c[i])
        {
            return false;
        }
        else if (a[i] <= b[i] && b[i] <= c[i])
        {
            long long tmp = min(b[i] - a[i] + 1, c[i] - b[i] + 1);
            tmp *= 2;
            ops += tmp;
        }
        ops += (target - sum);
        totops += ops;
        if (totops > k)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    long long k;
    long long ans = 0;
    cin >> n >> k;
    vector<long long> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    long long low = -3 * 1e9;
    long long high = 3 * 1e18;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (check(n, k, mid, a, b, c))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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