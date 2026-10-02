#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if (b % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    long long curr = 1;
    long long n = a + b + c;
    vector<pair<int, int>> pairs;

    for (int i = 1; i <= b / 2; i++)
    {
        pairs.push_back({curr, curr + 2});
        pairs.push_back({curr + 1, curr + 3});
        curr += 4;
    }
    long long nearest = c / 3;
    for (int i = 1; i <= nearest; i++)
    {
        pairs.push_back({curr, curr + 3});
        pairs.push_back({curr + 1, curr + 4});
        pairs.push_back({curr + 2, curr + 5});
        curr += 6;
    }
    int rem = c % 3;
    if (rem > a)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= rem; i++)
    {
        pairs.push_back({curr, curr + 3});
        pairs.push_back({curr + 1, curr + 2});
        curr += 4;
        a--;
    }
    for (int i = 1; i <= a; i++)
    {
        pairs.push_back({curr, curr + 1});
        curr += 2;
    }

    for (auto p : pairs)
    {
        cout << p.first << " " << p.second << endl;
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