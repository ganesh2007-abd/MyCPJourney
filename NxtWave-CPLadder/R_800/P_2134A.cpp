#include <bits/stdc++.h>
using namespace std;

int parity(long long a, long long b)
{
    if ((a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void solve()
{
    long long n, r, b;
    cin >> n >> r >> b;
    if (parity(n, b))
    {
        if (r <= b)
        {
            cout << "yes" << endl;
        }
        else
        {
            if (parity(r, b))
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }
    else
    {
        cout << "no" << endl;
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