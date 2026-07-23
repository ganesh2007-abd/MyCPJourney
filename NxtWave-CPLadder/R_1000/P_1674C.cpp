#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    string t;
    cin >> s;
    cin >> t;
    bool founda = false;
    for (auto ch : t)
    {
        if (ch == 'a')
        {
            founda = true;
            break;
        }
    }
    if (founda)
    {
        if (t.size() != 1)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << "1" << endl;
        }
    }
    else
    {
        cout << (1LL << s.size()) << endl;
    }
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}