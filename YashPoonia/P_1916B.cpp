#include <bits/stdc++.h>
using namespace std;

long long findgcd(long long a, long long b)
{
    a = llabs(a);
    b = llabs(b);
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve()
{
    long long a;
    long long b;
    cin >> a >> b;
    if (b % a != 0)
    {
        cout << (a / findgcd(a, b)) * b << endl;
    }
    else
    {
        cout << b * (b / a) << endl;
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