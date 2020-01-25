#include <bits/stdc++.h>

using namespace std;

long long  n, m;
const long long mod = 1e9+7;

class matrix
{
public:
    int sz;
    long long a[102][102];
    matrix (int _n)
    {
        sz = _n;
        memset(a, 0, sizeof(a));
    }
};

matrix operator * (matrix a, matrix b)
{
    matrix res(m);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                for (int k = 1; k <= m; k++)
                    res.a[i][j] = (res.a[i][j] + a.a[i][k]*b.a[k][j]%mod)%mod;
    return res;
}

matrix fast_pow(matrix x, long long y)
{
    if (y == 1)
        return x;
    matrix res = fast_pow(x, y/2);
    res = res*res;
    if (y%2)
        return res*x;
    return res;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    matrix p(m);
    for (int i = 1; i < m; i++)
        p.a[i][i+1] = 1;
    p.a[m][1] = p.a[m][m] = 1;
    if (n < m)
        return cout << 1, 0;
    if (n == m)
        return cout << 2, 0;
    matrix res = fast_pow(p, n-m);
    long long ans = 0;
    for (int i = 1; i < m; i++)
        ans = (ans+res.a[m][i])%mod;
    ans = (ans+res.a[m][m]*2LL)%mod;
    cout << ans;
    return 0;
}
