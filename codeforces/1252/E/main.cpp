#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3+100;
const long long mod = 1e9+7;
int n, m;
long long sr[maxn][maxn], sd[maxn][maxn], r[maxn][maxn], d[maxn][maxn], ssr[maxn][maxn], ssd[maxn][maxn];
char c[maxn][maxn];

void solve()
{
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
    {
        sr[i][j] = sr[i][j+1] + (c[i][j] == 'R');
        sd[i][j] = sd[i+1][j] + (c[i][j] == 'R');
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j --)
        {
            r[i][j] = (ssd[i][j+1] - ssd[i][j+(m-sr[i][j+1]-j)+1] + mod) % mod;
            d[i][j] = (ssr[i+1][j] - ssr[i+(n-sd[i+1][j]-i)+1][j] + mod)%mod;
            if (i == n && j == m)
                d[i][j] = r[i][j] = 1-(c[i][j] == 'R');
            else
                if (i == n)
            {
                d[i][j] = 0;
                if (sr[i][j+1])
                    r[i][j] = 0;
            } else
            {
                if (j == m)
                {
                    r[i][j] = 0;
                    if (sd[i+1][j])
                        d[i][j] = 0;
                }
            }
            ssr[i][j] = (ssr[i+1][j] + r[i][j])%mod;
            ssd[i][j] = (ssd[i][j+1] + d[i][j])%mod;
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i<= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    if (n == 1 && m == 1)
    {
        cout << 1 - (c[1][1] == 'R');
        return 0;
    }
    solve();
    cout << (r[1][1] + d[1][1])%mod;
    return 0;
}
