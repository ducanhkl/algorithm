#include <bits/stdc++.h>

using namespace std;


struct data
{
    int u, v;
    long long w;
};

const int maxn =  400;
const long long maxc = 5e18;
const long long mod = 1e9;
long long d[maxn][maxn], dp[maxn][maxn];
vector <data> e;
long long ans = 0;

int n, m;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1;  j <= n; j++)
    {
        d[i][j] = maxc;
        dp[i][j] = maxc;
    }
    for (int i = 1; i <= n; i++)
    {

        d[i][i] = 0;
        dp[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        long long u, v, w;
        cin >>u >> v >> w;
        d[u][v] = d[v][u] = 1;
        e.push_back({u, v, w});
        e.push_back({v, u, w});
    }
    for (int k = 1; k <= n; k++)
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= n; i++)
    {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    for (auto v : e)
    {
        for (int i = 1; i <= n; i++)
            for (int j = i+1; j <= n; j++)
        {
            dp[i][j] = min(dp[i][j], (d[i][v.u]+d[v.v][j]+1)*v.w);
            dp[i][j] = min(dp[i][j], (d[i][v.u]+d[v.u][j]+2)*v.w);
            dp[i][j] = min(dp[i][j], (d[i][v.v]+d[v.v][j]+2)*v.w);
            dp[i][j] = min(dp[i][j], (d[i][v.v]+d[v.u][j]+1)*v.w);

        }
    }
    int check = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (dp[i][j] == maxc)
                continue;
            ans = (ans+dp[i][j]);
            if (ans >= mod)
                check = true;
            ans %= mod;
        }
    }
    if (check)
    {
        if (ans == 0)
        {
            cout << "000000000";
            return 0;
        }
        int cnt = ceil(log10((long double)(ans + 1)));
        cnt = 9-cnt;
        for (int i = 1;i <= cnt; i++)
            cout << 0;
    }
    cout << ans;
    return 0;
}
