#include <bits/stdc++.h>
#define maxn 201

using namespace std;


int a[maxn], v[30], vt[maxn][30];
long long f[maxn][maxn][maxn], dd[maxn][maxn][maxn];
int n;

void init()
{
    memset(v, 0, sizeof(v));
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= 9; j++)
            vt[i][j] = v[j];
        v[a[i]] = i;
    }
    memset(dd, 0, sizeof(dd));
    return;
}
long long calc (int l, int r, int k)
{
    if (l > r)
        return k*k;
    if (l == r)
        return (k+1)*(k+1);
    if (dd[l][r][k])
        return f[l][r][k];
    long long res = 0;
    int t = l;
    for (t = l+1; t <= r; t++)
        if (a[t] != a[l])
            break;
    res = (t-l+k)*(t-l+k) + calc(t, r, 0);
    t = vt[l][a[l]];
    while (t > 0 && t <= r)
    {
        res = max(res, calc(l+1, t-1, 0) + calc(t, r, k+1));
        t = vt[t][a[l]];
    }
    f[l][r][k] = res, dd[l][r][k] = 1;
    return res;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        a[i] = (int)(x-'0');
    }
    init();
    cout << calc(1, n, 0);
    return 0;
}
