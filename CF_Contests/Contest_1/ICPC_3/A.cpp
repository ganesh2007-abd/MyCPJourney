#include <bits/stdc++.h>
using namespace std;

unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

bool ispossiblei(int i, string s)
{
    if (vowels.find(s[i]) != vowels.end() && vowels.find(s[i + 1]) == vowels.end() || vowels.find(s[i + 1]) != vowels.end() && vowels.find(s[i]) == vowels.end())
    {
        return true;
    }
    return false;
}

bool ispossiblej(int i, string s)
{
    if (vowels.find(s[i]) != vowels.end() && vowels.find(s[i - 1]) == vowels.end() || vowels.find(s[i - 1]) != vowels.end() && vowels.find(s[i]) == vowels.end())
    {
        return true;
    }
    return false;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            if (ispossiblei(i, s))
            {
                swap(s[i], s[i + 1]);
                if (s[i] == s[j])
                {
                    i++;
                    j--;
                    continue;
                }
                swap(s[i], s[i + 1]);
            }
            if (ispossiblej(j, s))
            {
                swap(s[j], s[j - 1]);
                if (s[i] == s[j])
                {
                    i++;
                    j--;
                    continue;
                }
                swap(s[j], s[j - 1]);
            }

            cout << "NO" << endl;
            return;
        }
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