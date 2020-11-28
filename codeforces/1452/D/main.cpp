#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
const long long mod = 998244353;
int n;
long long f[maxn], p[maxn];

long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    // cout << x <<  " " << y << " " << res << endl;
    res = res*res % mod;
    if (y%2)
        return (res*x) % mod;
    return res;
}

long long inv(long long x)
{
    return fast_pow(x, mod-2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = (p[i-1]*2) % mod;
    }
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = (f[i-1] + f[i-2])%mod;
    }
    // cout << inv(p[n]) << endl;
    cout << (f[n]*inv(p[n]))%mod;
    return 0;
}
