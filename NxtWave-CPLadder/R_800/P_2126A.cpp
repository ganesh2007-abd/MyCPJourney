/*

P-Only one digit

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int mindigit = INT_MAX;
    int dig;
    while (n > 0)
    {
        dig = n % 10;
        n = n / 10;
        mindigit = min(mindigit, dig);
    }
    cout << mindigit << endl;
}

int main()
{
    int t;
    cin >> t;
    int inp;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}