#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    stack<int> st;
    vector<bool> printed(n + 1, false);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            st.push(i + 1);
        }
        else if (s[i] == '2')
        {
            if (st.empty())
            {
                printed[i + 1] = true;
                cnt++;
                continue;
            }
            auto c = st.top();
            st.pop();
            printed[c] = true;
            cnt++;
        }
        else
        {
            printed[i + 1] = true;
            cnt++;
        }
    }
    cout << n - cnt << endl;
    for (int i = 1; i <= n; i++)
    {
        if (printed[i] == false)
        {
            cout << i << " ";
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
        // cout << "one done" << endl;
    }
}