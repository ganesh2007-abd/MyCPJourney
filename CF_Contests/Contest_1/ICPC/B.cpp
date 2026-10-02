// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     long long n;
//     cin >> n;
//     vector<long long> a;
//     vector<long long> b;

//     for (long long i = 0; i < n; i++)
//     {
//         long long tmp;
//         cin >> tmp;
//         a.push_back(tmp);
//     }

//     // cout << "input1 taken" << endl;
//     for (long long i = 0; i < n; i++)
//     {
//         long long tmp;
//         cin >> tmp;
//         b.push_back(tmp);
//     }
//     // cout << "input2 taken" << endl;
//     long long ans = 0;

//     for (long long i = 0; i < n - 1; i++)
//     {
//         // cout << "entered" << endl;
//         if (a[i] < b[i])
//         {
//             cout << -1 << endl;
//             return;
//         }
//         a[i + 1] += (a[i] - b[i]) * 2;
//         ans += (a[i] - b[i]);
//         a[i] = b[i];
//     }
//     // cout << "loop done" << endl;
//     if (a[n - 1] != b[n - 1])
//     {
//         cout << -1 << endl;
//     }
//     else
//     {
//         cout << ans << endl;
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<long long> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    long long ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < b[i])
        {
            cout << -1 << endl;
            return;
        }

        long long moves = a[i] - b[i];
        if (moves > 2000000000LL) // can never recover, avoids overflow
        {
            cout << -1 << '\n';
            return;
        }

        ans += moves;
        a[i + 1] += 2 * moves;
        a[i] = b[i];
    }

    if (a[n - 1] != b[n - 1])
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}