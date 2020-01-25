#include <bits/stdc++.h>

using namespace std;


const int maxn = 200;
const long long mod = 1e9+7;
int n, k, a[maxn];
long long cnt0 = 0, cnt = 0;

long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x%mod;
    long long res = fast_pow(x, y/2);
    res = res*res%mod;
    if (y%2)
        return res*x %mod;
    return res;
}

struct matrix
{
    long long a[maxn][maxn];
    void reset()
    {
        memset(a, 0, sizeof(a));
    }
};

matrix mul(matrix x, matrix y)
{
    matrix z;
    z.reset();
    for (int i = 0; i <= cnt0; i++)
        for (int j = 0; j <= cnt0; j++)
    {
        for (int k = 0; k <= cnt0; k++)
        {
            z.a[i][j] += (x.a[i][k]*y.a[k][j]%mod);
            z.a[i][j] %= mod;
        }
    }
    return z;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt0 += !a[i];
        }
    if (cnt0 == 0 || cnt0 == n)
    {
        cout << 1;
        return 0;
    }
    long long inv = fast_pow(1LL*n*(n-1)/2, mod-2);
    for (int i = 1; i <= cnt0; i++)
        cnt += !a[i];
    matrix res, ans;
    ans.reset();
    res.reset();
    ans.a[0][cnt] = 1;
    for (int i = 0; i <= cnt0; i++)
    {
        int all = 1;
        if (i < n)
        {
            long long  t = (cnt0 - i) * (cnt0-i) % mod;
            res.a[i][i+1] = t*inv%mod;
            all = (all - res.a[i][i+1] + mod)%mod;
        }
        if (i)
        {
            long long t = i*((n-cnt0) - (cnt0 - i))%mod;
            if (t < 0)
                continue;
            res.a[i][i-1] = t*inv%mod;
            all = (all - res.a[i][i-1] + mod)%mod;
        }
        res.a[i][i] = all;
    }
    for (int i = 1; i < 32; i++)
    {
        if (k&1)
            ans = mul(ans, res);
        k >>= 1;
        res = mul(res, res);
    }
    cout << ans.a[0][cnt0];
}
