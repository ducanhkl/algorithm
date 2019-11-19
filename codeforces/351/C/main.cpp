#include <bits/stdc++.h>

using namespace std;

const int maxn = 30, masz = 105;
int n, m, mxdeep;
int a[maxn], b[maxn];

struct ma
{
    long long d[masz][masz];
    void clear()
    {
        for (int i=0; i<masz; i++)
            for (int j=0; j<masz; j++)
                d[i][j] = 2e9;
    }
    void clean()
    {
        for (int i = 0; i < masz; i++)
            d[i][i] = 0;
    }
};


ma operator * (ma xx, ma yy)
{
    ma c;
    c.clear();
    for (int i = 0; i < mxdeep; i++)
        for (int j = 0; j < mxdeep; j++)
            for (int k = 0; k < mxdeep; k++)
            {
                long long &res = c.d[i][j];
                res = min(res, xx.d[i][k]+yy.d[k][j]);
            }
    return c;
}


ma bin_pow(ma x, long long b)
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
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    mxdeep = 2*n+1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    ma res, p;
    res.clear();
    res.clean();
    for (int i = 0; i < n; i++)
    {
        p.clear();
        for (int j = 0; j < mxdeep; j++)
        {
            if (j)
                p.d[j-1][j] = a[i];
            if (j+1<mxdeep)
                p.d[j+1][j] = b[i];
        }
        res = res*p;
    }
    ma ans;
    ans.clear();
    ans.d[0][0] = 0;
    ans = ans*bin_pow(res, m);
    cout << ans.d[0][0];
    return 0;
}
