#include <bits/stdc++.h>

using namespace std;


const int maxn = 101;
const long long maxc = INT_MAX;
int n, t;
int a[maxn];

struct matrix
{
    long long a[maxn][maxn];
    void reset()
    {
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++)
                a[i][j] = -maxc;
    }
};

matrix operator * (matrix a, matrix b)
{
    matrix x;
    x.reset();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                x.a[i][j] = max(a.a[i][k]+b.a[k][j], x.a[i][j]);
    return x;
}

matrix fast_pow(matrix x, long long y)
{
    if (y == 1)
        return x;
    matrix res = fast_pow(x, y/2);
    res = res*res;
    if (y%2)
        return x*res;
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    matrix d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] > a[j])
                {
                    d.a[i][j] = -maxc;
                    continue;
                }
            else
            {
                d.a[i][j] = 1;
                for (int k = 1; k < j; k++)
                    if (a[k] <= a[j])
                        d.a[i][j] = max(d.a[i][j], d.a[i][k]+1);
            }
    matrix res;
    res = fast_pow(d, t);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans = max(ans, (long long)res.a[i][j]);
    cout << ans;
    return 0;
}
