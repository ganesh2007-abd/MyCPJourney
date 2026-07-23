#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int m;
    cin >> n >> m;
    vector<int> start = {0, 0};
    long long pts = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        vector<int> end = {a, b};
        long long nobb = end[0] - start[0];
        if (start[1] != end[1])
        {
            if (nobb % 2 == 0)
            {
                pts += nobb - 1;
            }
            else
            {
                pts += nobb;
            }
        }
        else
        {
            if (nobb % 2 == 0)
            {
                pts += nobb;
            }
            else
            {
                pts += nobb - 1;
            }
        }
        start = end;
    }
    int e = m;
    int s = start[0];
    pts += (e - s);
    cout << pts << endl;
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