#include <bits/stdc++.h>

using namespace std;


const int maxn = 2*1e5+100;
long long dp[maxn][3], mx[maxn], dd[maxn][3], c[maxn];
int n;
vector <int> ans, e[maxn];

void dfs1(int u, int par)
{
    if (e[u].size() == 1 && u != 1)
    {
        dp[u][0] = c[u];
        dp[u][1] = 0;
        mx[u] = c[u];
        return ;
    }
    mx[u] =-1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if ( v == par)
            continue;
        dfs1(v, u);
        mx[u] = max(mx[u], dp[v][0] - dp[v][1]);
        dp[u][0] += dp[v][0];
        dp[u][1] += dp[v][0];
    }
    dp[u][1] -= mx[u];
    dp[u][0] = min(dp[u][0], dp[u][1] + c[u]);
    return ;
}

void dfs2(int u, int par, int s)
{
    if (dd[u][s] == true)
        return ;
    dd[u][s] = 1;
    int cnt = 0;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        if (dp[v][0] - dp[v][1] == mx[u])
            cnt++;
    }
    if (!s && mx[u] >= c[u])
        ans.push_back(u);
    if ((s || mx[u] > c[u]) && cnt == 1)
    {
        for (int i = 0; i  < e[u].size(); i++)
        {
            int v = e[u][i];
            if (v == par)
                continue;
            if (dp[v][0] - dp[v][1] == mx[u])
                dfs2(v, u, 1);
            else
                dfs2(v, u, 0);
        }
    } else
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i];
            if (v == par)
                continue;
            dfs2(v, u, 0);
        }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    cout << dp[1][0] << " "<< ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
