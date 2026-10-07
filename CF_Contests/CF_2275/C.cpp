#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> v(n);
    unordered_map<int, int> mpp;
    long long ans = 0;
    for (int i = 0; i + 4 < n; i++)
    {
        int al = nums[i] + nums[i + 2] - nums[i + 4];
        v[i] = al;
        long long cnt = mpp[al];
        if (i - 2 >= 0 && v[i - 2] == v[i])
        {
            cnt--;
        }
        if (i - 4 >= 0 && v[i - 4] == v[i])
        {
            cnt--;
        }
        ans += cnt;
        mpp[al]++;
        // // mpp[al] = cnt;
        // cout << al << " " << mpp[al] << endl;
        // cout << "ans:" << ans << endl;
    }
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
