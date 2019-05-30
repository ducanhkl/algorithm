#include <bits/stdc++.h>
#define maxn 200

using namespace std;

int fr[maxn], dp[maxn][2020], v[maxn], c[maxn];
vector <int> e[maxn];
int n, m;

void dfs(int u, int p)
{
    for (int i = 0; i <= m; i++)
        dp[u][i] = dp[p][i];
    fr[u] = false;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (fr[v])
            dfs(v, u);
    }
    for (int i = 0; i + c[u] <= m; i++)
        dp[p][i+c[u]] = max(dp[p][i+c[u]], dp[u][i] + v[u]);
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    for (int i = 0; i < maxn; i++)
        fr[i] = 1;
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        cin >> v[i];
    for (int i = 2; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << *max_element(dp[1], dp[1]+m+1);
    return 0;
}
