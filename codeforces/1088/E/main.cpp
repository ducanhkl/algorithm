#include <bits/stdc++.h>
#define maxn 300006

using namespace std;

long long dp[maxn], ans = LONG_MIN, a[maxn];
int n, k = 0;
vector <int> e[maxn];

void dfs1(int u, int par)
{
    dp[u] = a[u];
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs1(v, u);
        dp[u] += max(dp[v], 0LL);
    }
    ans = max(ans, dp[u]);
}

void dfs2(int u, int par)
{
    dp[u] = a[u];
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs2(v, u);
        dp[u] += max(dp[v], 0LL);
    }
    if (dp[u] == ans)
    {
        k ++;
        dp[u] = 0;
    }
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1, 0);
    memset(dp, 0, sizeof(dp));
    dfs2(1, 0);
    cout << ans*k << " " << k;
    return 0;
}
