#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int n, m;
vector <int> e[maxn];
int k, x;
long long dp[maxn][3][30];
const long long mod = 1e9+7;

void dfs(int u, int par = 0)
{
    dp[u][0][0] = dp[u][1][1] = dp[u][2][0] = 1;
    long long tmp[3][30];
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        memset(tmp, 0 ,sizeof(tmp));
        dfs(v, u);
        for (int j = 0; j <= x; j++)
             for (int h = 0; h+j <= x; h++)
        {
            tmp[0][j+h] = (tmp[0][j+h] + (dp[v][0][h] + dp[v][1][h]+dp[v][2][h])*dp[u][0][j]%mod)%mod;
            tmp[1][j+h] = (tmp[1][j+h] + dp[v][0][h]*dp[u][1][j]%mod)%mod;
            tmp[2][j+h] = (tmp[2][j+h] + (dp[v][0][h]+dp[v][2][h])*dp[u][2][j]%mod)%mod;
        }
        swap(tmp, dp[u]);
    }
    for (int i = 0; i <= x; i++)
    {
        dp[u][0][i] = dp[u][0][i]*(k-1)%mod;
        dp[u][2][i] = dp[u][2][i]*(m-k)%mod;
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin >> k >> x;
    dfs(1);
    long long res = 0;
    for (int i = 0; i <= x; i++)
        res = (res + dp[1][0][i] + dp[1][1][i] + dp[1][2][i])%mod;
    cout << res;
    return 0;
}
