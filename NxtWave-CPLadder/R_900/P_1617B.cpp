#include <bits/stdc++.h>
using namespace std;

long long gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    long long n;
    cin >> n;
    for (long long b = 2; b <= n; b++)
    {
        long long a = n - 1 - b;
        if (gcd(a, b) == 1)
        {
            cout << a << " " << b << " 1 " << endl;
            break;
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