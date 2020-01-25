#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+100;
const long long mod = 1e9+7;
long long ans = 1;
long long p[maxn], a[maxn], c[maxn];
int n;

long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    res = res*res%mod;
    if (y%2)
        return res*x%mod;
    return res;
}

long long calc_com(long long kk, long long nn)
{
    return p[nn]*fast_pow(p[kk]*p[nn-kk]%mod, mod-2)%mod;
}

int main()
{
    memset(c, 0, sizeof(c));
    p[0] = 1;
    for (int i = 1; i < maxn; i++)
        p[i] = (p[i-1]*i)%mod;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], c[i] = c[i-1] +a[i];
    for (int i = 1; i <= n; i ++)
        ans = ans*calc_com(c[i-1], c[i]-1)%mod;
    cout << ans;
    return 0;
}
