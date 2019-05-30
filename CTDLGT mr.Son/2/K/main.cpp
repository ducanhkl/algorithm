#include <bits/stdc++.h>

using namespace std;

int n, k;

const long long mod = 1e9+7;
long long ans = 0;
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
        cin >> n >> k;
        for (int i = 0; i < 20; i++) for (int j = 0; j < 20; j++) res.a[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> res.a[i][j];
        res = fast_pow(res, k);
        for (int i = 1; i <= n; i++, cout << endl)
            for (int j = 1; j <= n; j++)
                cout << res.a[i][j] << " " ;
    }
}
