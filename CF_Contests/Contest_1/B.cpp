#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    string ans = "YES";
    int low;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == 1)
        {
            if (i - 1 < 0)
                continue;
            else
            {
                low = arr[i - 1] + 1;
            }
        }
        else
        {
            if (i - 1 >= 0)
            {
                low = arr[i - 1] + 1;
            }
            else
            {
                low = 1;
            }
        }
        if (arr[i] == low)
            continue;
        else if (arr[i] > low)
        {
            arr[i + 1] += arr[i] - low;
            arr[i] = low;
            if (arr[i + 1] == low)
            {
                ans = "NO";
                break;
            }
        }
        else
        {
            ans = "NO";
            break;
        }
    }
    if (n - 2 >= 0)
    {
        if (arr[n - 1] <= arr[n - 2])
        {
            ans = "NO";
        }
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
