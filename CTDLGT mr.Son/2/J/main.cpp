#include <bits/stdc++.h>

using namespace std;

int n, k;

const long long mod = 1e9+7;
struct data
{
    long long a[20][20];
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
    n = 2;
    res.a[1][1] = 0; res.a[1][2] = res.a[2][1] = res.a[2][2] = 1;
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j < 20; j++)
            I.a[i][j] = 0;
        I.a[i][i] = 1;
    }
    int t;
    cin >> t;
    while (t--)
    {
        cin >> k;
        if (k == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (k == 1)
        {
            cout << 1 << endl;
            continue;
        }
        data ans = fast_pow(res, k-1);
        cout << ans.a[2][2] << endl;
    }
}
