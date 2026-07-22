#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

long long countdivisors(long long x)
{
    int ans = 1;

    for (long long i = 2; i * i <= x; i++)
    {
        int cnt = 0;
        while (x % i == 0)
        {
            cnt++;
            x /= i;
        }
        ans = ans * (cnt + 1);
    }
    if (x > 1)
        ans = ans * 2;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long g = 0;
    for (long long i = 0; i < n; i++)
    {
        g = gcd(g, a[i]);
    }
    cout << countdivisors(g) << endl;
}
