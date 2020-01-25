#include <bits/stdc++.h>

using namespace std;

int n;

const long long mod = 1e9+7;
long long h, ans = 0, arr[300];
struct data
{
    long long a[200][200];
} I;

data operator *(data x, data y)
{
    data z;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
    {
        z.a[i][j] = 0;
        for (int k = 1; k <= n; k++)
        {
            z.a[i][j] = (z.a[i][j] + x.a[i][k]*y.a[k][j])%mod;
        }
    }
    return z;
}

data fast_pow(data x, long long y)
{
    if (y == 0)
        return I;
    if (y == 1)
        return x;
    data res = fast_pow(x, y/2);
    if (y%2)
        return (res*res)*x;
    return res*res;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    data res;
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            I.a[i][j] = 0;
        I.a[i][i] = 1;
    }
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res.a[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
    {
        if (__builtin_popcountll(arr[i]^arr[j])%3 == 0)
        {
            res.a[j][i] = 1;
        }
    }
    res = fast_pow(res, h-1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans = (ans+res.a[i][j])%mod;
    cout << ans;
}
