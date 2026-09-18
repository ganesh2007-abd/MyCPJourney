#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    if (n % 2 != 0)
    {
        cout << '1' << endl;
        return;
    }
    for (int i = 1;; i++)
    {
        if (n % i != 0)
        {
            cout << i - 1 << endl;
            return;
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