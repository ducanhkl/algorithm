#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;

struct data{
    int u, v;
    long long w;

} g[maxn];

bool cmp(data x, data y)
{
    return x.w < y.w;
}

int root[maxn];
long long ans = 0;
int n, m;
set <int> s[maxn];
long long res[maxn];



int get_root(int u)
{
    if (root[u] == 0)
        return u;
    return root[u] = get_root(root[u]);
}

int add(int u, int v, long long w)
{
    if (s[u].size() > s[v].size())
        swap(s[u], s[v]);
    root[u] = v;
    while (s[u].size())
    {
        int edge = *s[u].begin();
        if (s[v].count(edge))
        {
            res[edge] -= w;
        } else {
            s[v].insert(edge);
        }
        s[u].erase(edge);
    }
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[i] = {u, v, w};
        s[u].insert(i);
        s[v].insert(i);
        res[i] = w;
    }
    sort(g+1, g+m+1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int u = g[i].u;
        int v = g[i].v;
        u = get_root(u);
        v = get_root(v);
        if (u == v)
            continue;
        add(u, v, g[i].w);
        ans += g[i].w;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << res[i] + ans << endl;
    }
    return 0;
}
