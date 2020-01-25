#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5+100;

int n, m;
int low[maxn], num[maxn], ans[maxn], g[maxn], par[maxn];
vector <pair <int, int> > e[maxn];

void dfs(int u, int p)
{
    low[u] = num[u];
    par[u] = p;
    for (auto ed : e[u])
    {
        int v = ed.first;
        int w = ed.second;
        if (v == p)
            continue;
        if (num[v] == 0)
        {
            g[v] = w;
            num[v] = num[u]+1;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if ((ans[v] || g[v]) && low[v] <= num[u])
                ans[u] = 1;
        } else
        if (num[v] < num[u])
        {
            low[u] = min(low[u], low[v]);
            if (w)
                ans[u] = 1;
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    int a, b;
    cin >> a >> b;
    num[a] = 1;
    g[a] = 0;
    dfs(a, 0);
    while (b)
    {
        if (ans[b] || g[b])
            return cout << "YES", 0;
        b = par[b];
    }
    cout << "NO";
    return 0;
}
