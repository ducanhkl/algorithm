#include <bits/stdc++.h>

using namespace std;

const long long maxn = 60000, mod = 1e9+7;
int n, b, k, x;
int a[maxn];

struct ma
{
    long long d[105][105];
    void clear()
    {
        memset(d, 0, sizeof(d));
    }
    void clean()
    {
        for (int i = 0; i < 105; i++)
            d[i][i] = 1;
    }
};

ma operator * (ma xx, ma yy)
{
    ma c;
    c.clear();
    for (int i = 0; i < x; i++)
        for (int j = 0; j < x; j++)
            for (int k = 0; k < x; k++)
            {
                long long &res = c.d[i][j];
                res = (res+xx.d[i][k]*yy.d[k][j]%mod)%mod;
            }
    return c;
}

ma bin_pow(ma x, int b)
{
    if (b == 1)
        return x;
    ma res = bin_pow(x, b/2);
    res = res*res;
    if (b%2)
        return res*x;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> b >> k >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ma t;
    t.clear();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < x; j++)
        {
            t.d[j][(j*10+a[i])%x] ++;
        }
    }
    ma ans = bin_pow(t, b);
    cout << ans.d[0][k];
    return 0;
}
