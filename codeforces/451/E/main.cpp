#include <bits/stdc++.h>
#define maxn 30

using namespace std;

const long long mod = 1e9+7;
int n;
long long f[maxn], s, p[maxn], ans = 0;


long long fast_pow(long long x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    if (y%2)
        return ((res*res)%mod)*x%mod;
    return (res*res)%mod;
}
long long c(long long x, long long y)
{
    if (x > y)
        return 0;
    long long res = 1;
    for (long long i = y; i > y-x; i--)
        res = (res*i)%mod;
    return (res*fast_pow(p[x], mod-2))%mod;
}
long long calc(int x)
{
    long long _s = s;
    for (int i = 0; i < n; i++)
        if ((x>>i)&1)
    {
        _s -= f[i+1]+1;
        if (_s < 0)
            return 0;
    }
    return c(n-1, (_s+n-1)%mod)%mod;
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    p[0] = 1;
    for (int i = 1; i < maxn; i++)
        p[i] = (p[i-1]*i)%mod;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> f[i];
    ans = 0;
    for (int i = 0; i < (1 << n); i++)
        {
            //cout << calc(i) << endl;
            if (__builtin_popcount(i)%2)
                ans = (ans - calc(i) + mod*mod)%mod;
            else ans = (ans + calc(i) + mod)%mod;
        }
    /*#define ll long long
    for(int i=0;i<(1<<n);i++)
	{
		int fu=1;ll sum=s;
		for(int j=0;j<n&&sum>=0;j++)
		if(i&(1<<j)){sum-=f[j]+1;fu*=-1;}
		if(sum>=0)ans=(ans+fu*c((sum+n-1)%mod,n-1))%mod;
	}*/
    cout << ans;
    return 0;
}
