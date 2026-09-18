#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    unordered_map<char, int> mpp;
    for (auto ch : s)
    {
        mpp[ch]++;
    }
    if (mpp['0'] == mpp['1'])
    {
        cout << '0' << endl;
        return;
    }
    string t = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            t += '1';
            mpp['1']--;
        }
        if (s[i] == '1')
        {
            t += '0';
            mpp['0']--;
        }
        if (mpp['0'] < 0 || mpp['1'] < 0)
        {
            cout << s.size() - i << endl;
            return;
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