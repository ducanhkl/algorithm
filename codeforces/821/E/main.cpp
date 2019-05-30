#include <bits/stdc++.h>
#define maxn 20

using namespace std;

struct matrix
{
    long long a[20][20];
    matrix ()
    {
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                a[i][j] = 0;
        a[0][0] = 1;
    }
};

matrix ans;
long long n, k, a[maxn], b[maxn], c[maxn];
long long h = 0;
long long mod = 1e9+7;


matrix operator *(matrix x, matrix y)
{
    matrix c;
    for (int i = 0; i < 20; i ++)
        for (int j = 0; j < 20; j++)
            c.a[i][j] = 0;
    for (int i = 0; i <= h; i++)
        for (int j = 0; j <= h; j++)
            for (int k = 0; k <= h; k++)
                c.a[i][j] = (c.a[i][j] + x.a[i][k]*y.a[k][j])%mod;
    return c;
}

matrix matrixpow(matrix x, long long y)
{
    matrix res;
    if (y == 0)
        return matrix();
    if (y == 1)
        return x;
    res = matrixpow(x, y/2);
    if (y % 2)
        return res*res*x;
    else return res*res;
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >>b[i] >> c[i];
        b[i] = min(b[i], k);
        h = max(h, c[i]);
    }
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            ans.a[i][j] = 0;
    ans.a[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        matrix cc;
        for (int j = 0; j < 20; j++)    for (int k = 0; k < 20; k++)    cc.a[j][k] = 0;
        for (int j = 0; j <= c[i]; j++)
        {
            cc.a[j][j] = 1;
            if (j >= 1) cc.a[j-1][j] = 1;
            if (j < c[i]) cc.a[j+1][j] = 1;
        }
        //for (int i = 0; i < 20; i++, cout << endl)  for (int j = 0; j < 20; j++)    printf("%4d", ans.a[i][j]);
        //cout << endl;
        //for (int i = 0; i < 20; i++, cout << endl)  for (int j = 0; j < 20; j++)    printf("%4d", cc.a[i][j]);
        //cout << endl << "CC" << endl;
        ans = ans*matrixpow(cc, b[i] - a[i]);
        //for (int i = 0; i < 20; i++, cout << endl)  for (int j = 0; j < 20; j++)    printf("%4d", ans.a[i][j]);
        //cout << endl;
        if (c[i] > c[i+1])
            for (int j = c[i+1] + 1; j <= h; j++)
                ans.a[0][j] = 0;
    }
    cout << ans.a[0][0];
    return 0;
}
