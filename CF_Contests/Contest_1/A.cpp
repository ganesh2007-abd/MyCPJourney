#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string page;
    cin >> page;

    long long maxi = INT_MIN;
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        if (page[i] == '*')
        {
            maxi = max(maxi, count);
            count = 0;
        }
        else
        {
            count++;
        }
    }
    maxi = max(maxi, count);
    if (maxi % 2 != 0)
    {
        cout << maxi / 2 + 1 << endl;
    }
    else
    {
        cout << maxi / 2 << endl;
    }
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