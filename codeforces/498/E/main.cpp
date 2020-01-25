#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7, maxn = 1<<7;

int full;

long long ans[maxn][maxn], res[maxn][maxn];


void mul (long long x[maxn][maxn], long long y[maxn][maxn])
{
    long long z[maxn][maxn];
    for (int i = 0; i < full; i++)
        for (int j = 0; j < (1<<7); j++)
    {
        z[i][j] = 0;
        for (int k = 0; k < full; k++)
            z[i][j] = (z[i][j]+x[i][k]*y[k][j])%mod;
    }
    memcpy(x, z, sizeof(z));
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < maxn; i++)
        ans[i][i] = 1;

    for (int t = 1; t <= 7; t++)
    {
        int w;
        cin  >> w;
        full = (1<<t);
        for (int i = 0; i < full; i++)
            for (int j = 0; j < full; j++)
        {
            res[i][j] = 0;
            for (int  h = 0; h < (full/2); h++)
            {
                if ((i | j | h | (h<<1)) == full-1)
                    res[i][j] ++;
            }
        }
        for (;w ; w >>= 1)
            {
                if (w &1)
                    mul(ans, res);
                mul(res, res);
            }
    }
    cout << ans[0][0];
    return 0;
}
