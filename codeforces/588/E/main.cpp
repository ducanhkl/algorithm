#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;
vector <int> e[maxn];
int n, m, q;
int h[maxn], p[maxn][22];

struct node
{
    int a[20];
    void init()
    {
        for (int i = 0; i < 12; i++)
            a[i] = INT_MAX;
    }
    int pb(int x)
    {
        if (x > a[10])
            return 0;
        a[10] = x;
        sort(a+1, a+11);
    }
    int show(int l)
    {
        for (int i = 1; i <= l; i++)
            cout << a[i] << " ";
        return 0;
    }
}  people[maxn][22];

node meger(node a, node b)
{
    node res;
    res.init();
    int l1 = 1, l2 = 1;
    for (int i = 1; i <= 10; i++)
        if (a.a[l1] < b.a[l2])
            res.a[i] = a.a[l1++];
        else
            res.a[i] = b.a[l2++];
    return res;
}

void dfs(int u, int par)
{
    p[u][0] = par;
    h[u] = h[par]+1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs(v, u);
    }
}


void rmq()
{
    for (int i = 1; i <= 20; i++)
        for (int u = 1; u <= n; u++)
            {
                p[u][i] = p[p[u][i-1]][i-1];
                people[u][i] = meger(people[u][i-1], people[p[u][i-1]][i-1]);
            }
}

node lca(int u, int v)
{
    node res;
    res.init();
    if (h[u] < h[v])
        swap(u, v);
    int len = h[u] - h[v];
    for (int i = 20; i >= 0; i --)
        if ((len>>i)&1)
            {
                res = meger(res, people[u][i]);
                u = p[u][i];
            }
    if (u == v)
        return meger(res, people[u][0]);
    for (int i = 20; i >= 0; i --)
        if (p[u][i] != p[v][i])
    {
        res = meger(res, people[v][i]);
        res = meger(res, people[u][i]);
        v = p[v][i];
        u = p[u][i];
    }
    res = meger(res, people[u][0]);
    res = meger(res, people[v][1]);
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < 20; j++)
            people[i][j].init();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        people[x][0].pb(i);
    }
    dfs(1, 0);
    rmq();
    while (q--)
    {
        int u, v, k, l;
        cin >> u >> v >> k;
        node x = lca(u, v);
        for (int i = 1; i <= k+1; i++)
        {
            if (i == k+1)
            {
                l = k;
                    break;
            }
            if (x.a[i] > m)
            {
                l = i-1;
                break;
            }
        }
        cout << l << " ";
        x.show(l);
        cout << endl;
    }
    return 0;
}
