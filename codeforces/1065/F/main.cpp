#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
vector <int> e[maxn];
int n, k;
int low[maxn], dp1[maxn], dp2[maxn], h[maxn];

void dfs(int u)
{
    if (e[u].size() == 0)
        low[u] = h[u], dp1[u] = 1;
    else
        low[u] = n;
    for (auto &v : e[u])
    {
        h[v] = h[u] + 1;
        dfs(v);
        if (low[v] - h[u] <= k)
        {
            dp1[u] += dp1[v];
            low[u] = min(low[u], low[v]);
            dp2[u] = max(dp2[u], dp2[v] - dp1[v]);
        } else
            dp2[u] = max(dp2[u], dp2[v]);
    }
    dp2[u] += dp1[u];
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        int v;
        cin >> v;
        e[v].push_back(i);
    }
    dfs(1);
    cout << dp2[1];
    return 0;
}
