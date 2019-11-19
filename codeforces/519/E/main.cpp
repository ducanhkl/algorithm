#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

int n, par[maxn][30], h[maxn], cnt[maxn];
vector <int> e[maxn];

void dfs(int u, int p)
{
    h[u] = h[p]+1;
    par[u][0] = p;
    cnt[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == p)
            continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
    return;
}

void rmq()
{
    for (int i = 1; i <= 20; i++)
        for (int u = 1; u <= n; u++)
            par[u][i] = par[par[u][i-1]][i-1];
    return;
}

int lca(int u, int v)
{
    if (h[u] < h[v])
        swap(u, v);
    for (int i = 20; i >= 0; i--)
        if (((h[u] - h[v])>>i)&1)
            u = par[u][i];
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
        if (par[u][i] != par[v][i])
    {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    rmq();
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        int l = lca(u, v);
        int p = h[u] + h[v] - 2*h[l];
        if (p%2)
        {
            cout << 0 << endl;
            continue;
        }
        p = p/2 - 1;
        if (h[u] == h[v])
        {
            for (int p2 = 20; p2 >= 0; p2 --)
                if ((p>>p2)&1)
            {
                u = par[u][p2];
                v = par[v][p2];
            }
            cout << n - cnt[u] - cnt[v] << endl;
            continue;
        }
        if (h[u] < h[v])
            swap(u, v);
        for (int p2 = 20; p2 >= 0; p2--)
            if ((p>>p2)&1)
                u = par[u][p2];
        cout << cnt[par[u][0]] - cnt[u] << endl;
    }
}
