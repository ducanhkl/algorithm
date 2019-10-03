#include <bits/stdc++.h>

using namespace std;

const long long maxn = 2e5+100, mod = 998244353;

int n;
long long lf = 0, rg = 0;
long long cur;
int a[maxn], use[maxn], g[maxn];
int tr[maxn];
long long ans = 0;

long long binpow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = binpow(x, y/2);
    res = res*res%mod;
    if (y%2)
        return res*x%mod;
    return res;
}


int mul(int a, int b){
	return (a * 1ll * b) % mod;
}


int bp(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

void upd(int x)
{
    for (; x > 0; x -= (x&(-x)))
        tr[x] ++;
    return ;
}

int get(int x)
{
    long long res = 0;
    for (; x < maxn; x += (x&(-x)))
        res += tr[x];
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(use, 0, sizeof(use));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > -1)
        {
            use[a[i]] = 1;
        }
    }
    cur = 0;
    for (int i = n; i >= 1; i--)
    {
        g[i] =  cur;
        cur += !use[i];
    }
    ans = (1LL*cur*(cur-1)%mod)*binpow(4, mod-2)%mod;
    long long inv = binpow(cur, mod-2);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1)
        {
            lf ++;
            continue;
        }
        ans = (ans + 1LL*lf * g[a[i]]%mod*inv%mod)%mod;
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == -1)
        {
            rg++;
            continue;
        }
        ans = (ans + 1LL*rg*(cur-g[a[i]])%mod*inv%mod)%mod;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1)
            continue;
        ans += get(a[i]);
        ans %= mod;
        upd(a[i]);
    }
    cout << ans;
    return 0;
}
