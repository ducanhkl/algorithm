#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

int cnt[maxn], par[maxn][30], n, m, h[maxn];
long long up[maxn], down[maxn], cnt1, cnt2, len1, len2;
vector <int> e[maxn];

void dfs1(int u, int p)
{
    cnt[u] = 1;
    par[u][0] = p;
    h[u] = h[p]+1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == p)
            continue;
        dfs1(v, u);
        cnt[u] += cnt[v];
        down[u] += down[v]+cnt[v];
    }
}

void dfs2(int u, int p, long long d)
{
    up[u] = d;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == p)
            continue;
        long long cur = n-cnt[v];
        long long d1 = d+down[u]-(down[v]+cnt[v])+cur;
        dfs2(v, u, d1);
    }
}

void rmq()
{
    for (int i = 1; i <= 20; i++)
        for (int u = 1; u <= n; u++)
            par[u][i] = par[par[u][i-1]][i-1];
    return;
}

int getpar(int u, int d)
{
    for (int i = 20; i >= 0; i--)
        if ((d>>i)&1)
            u = par[u][i];
    return u;
}

int lca(int u, int v)
{
    if (h[u] < h[v])
        swap(u, v);
    int len = h[u] - h[v];
    u = getpar(u, len);
    if (v==u)
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
    cin >> n >> m;
    for (int i = 1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    rmq();
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (h[u] < h[v])
            swap(u, v);
        int w = lca(u, v);
        int d = h[u] + h[v] - 2*h[w];
        if (v == w)
        {
            cnt2 = cnt[u];
            len2 = down[u];
            int uu = getpar(u, h[u]-h[v]-1);
            cnt1 = n-cnt[uu];
            len1 = up[uu]-(n-cnt[uu]);
        } else
        {
            cnt1 = cnt[u];
            cnt2 = cnt[v];
            len1 = down[u];
            len2 = down[v];
        }
        long double tu = cnt1*len2 + cnt2*len1 + (d+1)*cnt1*cnt2;
        long double mau = cnt1*cnt2;
        cout << fixed << setprecision(10) << tu/mau << endl;
    }
    return 0;
}
