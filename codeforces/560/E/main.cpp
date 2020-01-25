#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

typedef pair <long long, long long> pii;
long long dp[maxn], n, h, w, p[2*maxn];
pii a[maxn];
const long long mod = 1e9+7;

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
    else return res;
}

long long com(int kk, int nn)
{
    if (kk == 0)
        return 1;
    if (kk > nn || kk < 0)
        return 0;
    return p[nn]*fast_pow(p[kk]*p[nn-kk]%mod, mod-2)%mod;
}
long long calc(pii x, pii y)
{
    int kk = y.first - x.first;
    int nn = y.first + y.second - x.first - x.second;
    //cout << com(kk, nn);
    return com(kk, nn);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    p[0] = 1;
    for (long long i = 1; i <= 2*maxn; i++)
        p[i] = p[i-1]*i%mod;
    cin >> h >> w >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    n++;
    a[n] = {h, w};
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = calc({1, 1}, a[i]);
        for (int j = 1; j < i; j++)
            if (a[i].first >= a[j].first && a[i].second >= a[j].second)
                dp[i] = (dp[i] - dp[j]*calc(a[j], a[i])%mod + 2*mod)%mod;
    }
    cout << dp[n];
    return 0;
}
