
#include <bits/stdc++.h>

using namespace std;


const int maxn = 600;
const long long mod = 1e9+7;

int n;

int a[maxn][maxn];
long long dp[3][maxn][maxn];

long long dfs(int cn, int u, int v)
{
    if (cn && a[u][v] == 0)
    {
        return 0;
    }
    if (u == v)
    {
        return 1;
    }
    if (dp[cn][u][v] != -1)
    {
        return dp[cn][u][v];
    }
    long long sum = 0;
    if (cn == 0)
    {
        for (int i = u+1; i <= v; i++)
        {
            long long res = dfs(1, u, i)*dfs(0, i, v) % mod;
            sum = (sum + res )%mod;
        }
    } else
    {
        for (int i = u; i <= v-1; i++)
        {
            long long res = dfs(0, u, i)*dfs(0, i+1, v) % mod;
            sum = (sum + res)%mod;
        }
    }
    dp[cn][u][v] = sum;
    return sum;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    long long res = dfs(0, 1, n);
    cout << res;
    return 0;
}
