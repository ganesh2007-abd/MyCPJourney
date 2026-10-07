#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y, d;
    cin >> x >> y >> d;
    cout << (x - d) << " " << y << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}