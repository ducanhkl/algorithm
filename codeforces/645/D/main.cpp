#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, m;
int dp[maxn], res[maxn];
vector <pair <int, int> > e[maxn];

int dfs(int u)
{
    if (dp[u])
        return dp[u];
    dp[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].first;
        int cnt = e[u][i].second;
        int val = dfs(v);
        if (val+1 > dp[u])
        {
            dp[u] = val+1;
            res[u] = max(res[v], cnt);
        }
    }
    return dp[u];
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, i});
    }
    for (int i = 1; i <= n; i++)
        if (dfs(i) == n)
    {
        cout << res[i];
        return 0;
    }
    cout << -1;
    return 0;
}
