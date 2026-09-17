#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n - 1;
    int i = 0;
    int j = n - 1;
    while (i <= j && s[i] == 'B')
    {
        i++;
        ans--;
    }
    while (i <= j && s[j] == 'A')
    {
        j--;
        ans--;
    }
    ans = max(ans, 0);
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