#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }
    if (n == 1)
    {
        cout << arr[0] << endl;
        return;
    }
    // else if(n==2){
    //     cout<<arr[0] &
    // }
    long long ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        ans = ans & arr[i];
    }
    cout << ans << endl;
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