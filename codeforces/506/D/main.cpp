#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, m, q;
map<int, int>  rt[maxn], ans[maxn];

int getrt(int u, int w)
{
    if (rt[u][w] == u)
        return u;
    return rt[u][w] = getrt(rt[u][w], w);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (!rt[u][w])
            rt[u][w] = u;
        if (!rt[v][w])
            rt[v][w] = v;
        u = getrt(u, w);
        v = getrt(v, w);
        if (u != v)
            rt[v][w] = u;
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        if ((u > v && rt[u].size() == rt[v].size()) || rt[u].size() > rt[v].size())
            swap(u, v);
        if (!ans[u].count(v))
        {
            auto &it = ans[u][v];
            for (auto x: rt[u])
                if (rt[v].count(x.first) != 0 && rt[getrt(u, x.first)][x.first] == rt[getrt(v, x.first)][x.first])
                    it ++;
        }
        cout << ans[u][v] << endl;
    }
    return 0;
}

