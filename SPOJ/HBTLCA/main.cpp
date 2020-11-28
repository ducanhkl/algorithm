#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int ufr[maxn], h[maxn];
int par[maxn][30];
int r, cnt = 0;
vector <int> e[maxn];
int n;

int dfs(int u, int p)
{
    ufr[u] = cnt;
    par[u][0] = p;
    h[u] = h[p]+1;
    for (auto v : e[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
    return 0;
}

void rmq()
{
    for (int i = 1; i <= 22; i ++)
    {
        for (int u = 1; u <= n; u++)
        {
            par[u][i] = par[par[u][i-1]][i-1];
        }
    }
}

int get_par(int u, int len)
{
    for (int i = 22; i >= 0; i--)
    {
        if ((len >> i) & 1)
        {
            u = par[u][i];
        }
    }
    return u;
}

int lca(int u, int v)
{
    if (h[u] < h[v])
    {
        swap(u, v);
    }
    u = get_par(u, h[u] - h[v]);
    if (u == v)
    {
        return u;
    }
    for (int i = 22; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}


void init()
{
    for (int i = 1; i <= n; i++)
    {
        if (ufr[i] == 0)
        {
            cnt ++;
            dfs(i, i);
        }
    }
    rmq();
}

int dis(int u, int v)
{
    return h[u] + h[v] - 2*h[lca(u, v)];
}

bool check(int res, int u, int v, int root)
{
    // cout << dis(u, v) << " " << (dis(res, u) + dis(res, v) - 2*dis(res, root)) << endl;
    return dis(u, v) == (dis(root, u) + dis(root, v) - 2*dis(res, root));
}

void get_ans(int u, int v)
{
    int res = lca(u, v);
//    cout << dis(5, 6) << " " << dis(1, 5) << " " << dis(1, 6) << " " << dis(1, 1) << endl;
    if (check(res, u, v, r))
    {
        cout << res;
        return;
    }
    res = lca(r, u);
    if (check(res, u, v, r))
    {
        cout << res;
        return ;
    }
    res = lca(r, v);
    if (check(res, u, v, r))
    {
        cout << res;
        return;
    }
}

void solve()
{
    int q;
    cin >> q;
    for (int i  = 1; i <= q; i++)
    {
        char c;
        cin >> c;
        if (c == '!')
        {
            cin >> r;
        }
        else
        {
            int u, v;
            cin >> u >> v;
            get_ans(u, v);
            cout << endl;
        }
    }
}

int main()
{
    //  freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            exit(0);
        }
        for (int i = 1; i <= n; i++)
        {
            e[i].resize(0);
            h[i] = 0;
            ufr[i] = 0;
        }
        for (int i = 1; i < n; i ++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        r = 1;
        init();
        solve();
    }
    return 0;
}
