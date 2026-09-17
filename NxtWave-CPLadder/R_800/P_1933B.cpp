#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int num : arr)
    {
        sum += num;
    }
    if (sum % 3 == 0)
    {
        cout << "0" << endl;
        return;
    }
    int ans = 3 - (sum % 3);
    for (int num : arr)
    {
        if (((sum - num) % 3) == 0)
        {
            ans = 1;
            break;
        }
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