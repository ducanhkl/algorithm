#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
const long long mod = 1e9+7;
long long n, l[maxn], r[maxn];
long long p[maxn], pi[maxn];
long long ans = 0, sum = 0;


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
    else
        return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin>> l[i];
    for (int j = 1; j <= n; j++)
        cin >> r[j];
    for (int i = 1; i <= n; i++)
        pi[i] = fast_pow(r[i]-l[i]+1, mod-2);
    for (int i = 1; i < n; i++)
    {
        int ll = max(l[i], l[i+1]);
        int rr = min(r[i], r[i+1]);
        if (ll <= rr)
        {
            p[i] = (pi[i]*pi[i+1])%mod*1LL*(rr-ll+1)%mod;
            sum  = (sum+p[i])%mod;
        }
    }
    for (int i = 1; i+1 < n; i++)
    {
        int ll = max(l[i], max(l[i+1], l[i+2]));
        int rr = min(r[i], min(r[i+1], r[i+2]));
        if (ll <= rr)
        {
            long long value = (rr-ll+1)*1LL*pi[i]%mod*pi[i+1]%mod*pi[i+2]%mod;
            ans = (ans+value)%mod;
        }
    }
    ans = (ans*2)%mod;
    ans = (ans+sum)%mod;
    for (int i = 1; i < n; i++)
    {
        long long value = p[i]*((sum-(p[i]+p[i-1]+p[i+1])%mod+mod*mod)%mod)%mod;
        ans = value+ans;
        ans %= mod;
    }
    ans = (ans + n*n%mod - 2*n*sum%mod + mod*mod)%mod;
    cout << ans;
    return 0;
}
