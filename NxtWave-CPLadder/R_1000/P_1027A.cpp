#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j] && abs(s[i] - s[j]) != 2)
        {
            cout << "NO" << endl;
            return;
        }
        i++;
        j--;
    }
    cout << "YES" << endl;
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