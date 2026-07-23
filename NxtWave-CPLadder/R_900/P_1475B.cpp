#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    // if (n % 2020 == 0)
    // {
    //     cout << "YES" << endl;
    //     return;
    // }
    // else if (n % 2021 == 0)
    // {
    //     cout << "YES" << endl;
    //     return;
    // }

    while (n >= 0)
    {
        if (n % 2021 == 0)
        {
            cout << "YES" << endl;
            return;
        }
        n = n - 2020;
    }

    cout << "NO" << endl;
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