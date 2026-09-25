#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> sieve(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i; j <= n; j += i)
            {
                sieve[j] += 1;
            }
        }
    }
    int cnt = 0;
    for (auto num : sieve)
    {
        if (num == 2)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}