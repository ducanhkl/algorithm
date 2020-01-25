#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
const long long maxn = 400, mod = 1e9+7;
long long ans = 1;
map <int, int> m;
int t = 0;
long long c[2*maxn][2*maxn], f[maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (long long j = 2; j <= sqrt(x)+1; j++)
            while (x % (j*j) == 0)
                x /= j*j;
        m[x] ++;
    }
    for (int i = 0; i <= 2*n; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
    }
    f[0][0] = 1;
    t = 0, cnt = 0;
    for (auto x : m)
    {
        int sz = x.second;
        for (int i = 1; i <= sz; i++)
            ans = (ans*i)%mod;
        for (int i = 0; i <= t; i++)
            if (f[cnt][i])
        {
            for (int j = 1; j <= sz; j++)
            {
                for (int k = 0; k <= j && k <= i; k++)
                {
                    long long &dp = f[cnt+1][i-k+sz-j];
                    dp = (dp+f[cnt][i]*c[i][k]%mod*c[sz-1][j-1]%mod*c[t+1-i][j-k]%mod)%mod;
                }
            }
        }
        cnt ++;
        t += sz;
    }
    cout << ans*f[cnt][0]%mod;
    return 0;
}
