#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    long long sum = 0;
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i - 1];
        sum += arr[i - 1];
        prefix[i] = arr[i - 1] + prefix[i - 1];
    }

    for (int i = 0; i < q; i++)
    {
        long long ssum = sum;
        long long l, r, k;
        cin >> l >> r >> k;
        ssum = ssum - (prefix[r] - prefix[l - 1]) + k * (r - l + 1);
        if (ssum % 2 == 1)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
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