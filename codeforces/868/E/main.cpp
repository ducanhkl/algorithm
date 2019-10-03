#include <bits/stdc++.h>

using namespace std;

int dfs(int u, int par)
{
    int res = 0;
    for (auto [v, w] : e[u])
    {
        if (v == par)
            continue;
        res += dfs(v, u);
    }
    return res;
}

int dp(int u, int par, int k, int cnt)
{
    int &ans = dp[u][par][k][cnt];
    if (ans != -1)
    {

    }
}
int main()
{
    //ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    cin >> s;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int val;
        cin >> val;
        x[val]++;
    }
    for (auto [v, w] : e[s])
    {
        int cnt = dfs(v, s);
        ans = min(ans, dp(v, s, m, cnt));
    }
    cout << ans;
    return 0;
}
