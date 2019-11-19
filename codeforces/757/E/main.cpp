#include <bits/stdc++.h>
#define maxn 1000006


using namespace std;

long long f[maxn][30];
const long long mod = 1e9+7;

void init()
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < 30; j++)
            f[i][j ] = 0;
    for (int i = 0; i < 30; i++)
        f[0][i] = 2;
    f[0][0] = 1;
    for (int i = 1; i < maxn; i++)
        f[i][0] = 1;
    for (int i = 1; i <= maxn; i++)
        for (int j = 1; j <= 23; j++)
            //for (int k = j; k >= 0; k--)
    {
        f[i][j] = (f[i][j-1] + f[i-1][j])%mod;
    }
}

int calc(int r, int n)
{
    long long p = 1, res = 1;
    while (p <= sqrt(n))
    {
        int dem = 0;
        p++;
        while (n%p ==0)
            n/=p, dem++;
        if (dem != 0)
            res = res*f[r][dem]%mod;
    }
    if (n != 1)
        res = res*f[r][1]%mod;
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int r, n, q;
    init();
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int r, n;
        cin >> r >> n;
        cout << calc(r, n) << endl;
    }
    return 0;
}
