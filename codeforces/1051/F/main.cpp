#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int n, m, cnt = 0;
long long kc[60][maxn], par[maxn][60], h[maxn], d[maxn];
vector <pair<int, long long> > e[maxn];
int ufr[maxn];
const long long maxc = 1e14;

void rmq(int u)
{
    for (int i = 1; i <= 20; i++)
        par[u][i] = par[par[u][i-1]][i-1];
    return ;
}

void ijk(int x)
{
    for (int i = 0; i < maxn; i++)
        kc[cnt][i] = maxc;
    kc[cnt][x] = 0;
    priority_queue <pair <int, int> > q;
    q.push({0, x});
    while (q.size())
    {
        int u = q.top().second;
        int w = -q.top().first;
        q.pop();
        if (kc[cnt][u] < w)
            continue;
        for (int i = 0; i < (int)e[u].size(); i++)
        {
            int v = e[u][i].first;
            int l = e[u][i].second;
            if (kc[cnt][u] + l < kc[cnt][v])
            {
                kc[cnt][v] = kc[cnt][u]+l;
                q.push({-kc[cnt][v], v});
            }
        }
    }
}


void dfs(int u, int p)
{
    ufr[u] = 1;
    for (int i = 0; i < (int)e[u].size(); i++)
    {
        int v = e[u][i].first;
        if (v == p)
            continue;
        if (ufr[v] == 0)
        {
            par[v][0] = u;
            h[v] = h[u]+1;
            d[v] = d[u]+e[u][i].second;
            rmq(v);
            dfs(v, u);
        } else
        {
            cnt++;
            ijk(v);
        }
    }
}

int getpar(int u, int l)
{
    for (int i = 20; i >= 0; i--)
        if ((l>>i)&1)
            u = par[u][i];
    return u;
}

int lca(int u, int v)
{
    if (h[u] < h[v])
        swap(u, v);
    u = getpar(u, h[u]-h[v]);
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(ufr,0, sizeof(ufr));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    h[1] = 1;
    for (int i = 0; i <= 20; i++)
        par[1][i] = 1;
    dfs(1, 0);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        int p = lca(u, v);
        long long ans = d[u]+d[v]-2*d[p];
        for (int j = 1; j <= cnt; j++)
            ans = min(ans, kc[j][u] + kc[j][v]);
        cout << ans<< endl;
    }
    return 0;
}
