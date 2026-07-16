#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    // int i = n - 1;
    // while (i > 0)
    // {
    //     if (n % i == 0)
    //     {
    //         cout << i << " " << n - i << endl;
    //         break;
    //     }
    //     i--;
    // }
    bool found = false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << n / i << " " << n - n / i << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "1 " << n - 1 << endl;
    }
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