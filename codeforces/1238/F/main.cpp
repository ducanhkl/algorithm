#include <bits/stdc++.h>

using namespace std;

const int maxn = 3*1e5+100;
int n, ans, dp[maxn];
vector <int> e[maxn];

void dfs(int u, int par)
{
    int cnt = 0;
    for (auto v : e[u])
    {
        if (v == par)
            continue;
        cnt ++;
        dfs(v, u);
    }
    int mx1 = 1, mx2 = 1;
    dp[u] = 1;
    for (auto v : e[u])
    {
        if (v == par)
            continue;
        dp[u]  = max(dp[u], dp[v] + cnt);
        if (dp[v] > mx1)
            {
                mx2 = mx1;
                mx1 = dp[v];
            } else
            {
                mx2 = max(mx2, dp[v]);
            }
    }
    int res = mx1 + mx2 + cnt - 1;
    if (par)
        res++;
    ans = max(ans, res);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            e[i].resize(0);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >>u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ans = 0;
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}
