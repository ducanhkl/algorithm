#include <bits/stdc++.h>

using namespace std;

const long long mod =  1000000007;
long long l, r, k;
long long ans;

struct data
{
    long long a[5][5];
    void reset()
    {
        memset(a, 0, sizeof(a));
    }
};

data mul(data x, data y)
{
    data z;
    z.reset();
    for (int i = 0; i < 3 ;i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                z.a[i][j] = (z.a[i][j] + x.a[i][k]*y.a[k][j]%mod)%mod;
            }
        }
    }
    return z;
}

data b_pow_data(data x, long long y)
{
    if (y == 1)
        return x;
    data res = b_pow_data(x, y/2);
    res = mul(res, res);
    if (y%2)
        return mul(res, x);
    return res;
}


long long get(long long n)
{
    data a;
    a.reset();
    a.a[0][0] = a.a[0][1] = a.a[1][0] = 1;
    a = b_pow_data(a, k);
    a.a[0][2] = 1;
    a.a[1][2] = 1;
    a.a[2][2] = 1;
    a = b_pow_data(a, (n/k)+1);
    return a.a[0][2];
}

void solve()
{
    long long res2 = get(r);
    long long res1 = get(l-1);
    ans = res2 - res1 + mod;
    ans %= mod;
}

int main()
{
    //freopen("inp.ttx", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    int dem = 1;
    while (test--)
    {
        ans = 0;
        cin >> l >> r >> k;
        solve();
        cout << "Case "  << dem << ": " << ans << endl;
        dem ++;
    }
    return 0;
}
