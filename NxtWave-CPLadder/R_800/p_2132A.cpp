#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int m;
    cin >> n;
    string a;
    cin >> a;
    cin >> m;
    string b;
    string c;
    cin >> b;
    cin >> c;

    for (int i = 0; i < m; i++)
    {
        if (c[i] == 'D')
        {
            a += b[i];
        }
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < m; i++)
    {
        if (c[i] == 'V')
        {
            a += b[i];
        }
    }
    reverse(a.begin(), a.end());
    cout << a << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}