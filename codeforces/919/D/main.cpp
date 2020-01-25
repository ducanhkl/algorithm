#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, m, ans = 0;
string a;
int dd[maxn], dp[maxn][30];
vector <int> e[maxn];

int dfs(int u)
{
    dd[u] = -1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if ((!dd[v] && !dfs(v)) || dd[v] == -1)
            return 0;
        for (int j = 0; j <= 26; j++)
            dp[u][j] = max(dp[u][j], dp[v][j]);
    }
    dp[u][a[u]-'a'] ++;
    ans = max(ans,dp[u][(int)(a[u]-'a')]);
    dd[u] = 1;
    return dd[u];
}
int main()
{
    memset(dp, 0, sizeof(dp));
    memset(dd, 0, sizeof(dd));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> a;
    a = '0' + a;
    //cout << a;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!dd[i])
            if (!dfs(i))
            return cout << -1, 0;
    cout << ans;
    return 0;
}
