#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int n, m = 0, ri[maxn], ufr[maxn], check[maxn];
long long l[maxn], pre[maxn], r[maxn], suf[maxn], ans = LONG_MAX, best = 0, maxx = 0, d[maxn], f[maxn], root;
vector <pair<int, long long> > e[maxn];

int dfs1(int u, int par)
{
    if (ufr[u] == 1)
    {
        root = u;
        check[u] = 1;
        return 1;
    }
    ufr[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].first;
        long long w = e[u][i].second;
        if (v == par)
            continue;
        int res = dfs1(v, u);
        if (res == 0)
            continue;
        if (res == 1)
        {
            ri[++m] = u;
            d[m] = w;
            check[u] = 1;
            if (u != root)
                return 1;
        }
        return 2;
    }
    return 0;
}

long long dfs2(int u, int par)
{
    if (u == 6)
        n = n;
    long long max1 = 0, max2 = 0, tmp = 0;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].first;
        long long w = e[u][i].second;
        if (v == par || check[v])
            continue;
        tmp = dfs2(v, u)+w;
        if (tmp > max1)
        {
            max2 = max1;
            max1 = tmp;
        } else
            max2 = max(max2, tmp);
    }
    f[u] = max1;
    best = max(best, max1+max2);
    return max1;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(ri, 0, sizeof(ri));
    memset(ufr, 0, sizeof(ufr));
    memset(l, 0, sizeof(l));
    memset(pre, 0, sizeof(pre));
    memset(r, 0, sizeof(r));
    memset(suf, 0, sizeof(suf));
    memset(d,0, sizeof(d));
    memset(f, 0, sizeof(f));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs1(1, 0);
    for (int i = 3; i <= m; i++)
        d[i] += d[i-1];
    for (int i = 1; i <= m; i++)
        dfs2(ri[i], 0);
    l[1] = pre[1] = maxx = f[ri[1]];
    for (int i = 2; i <= m; i++)
    {
        l[i] = max(l[i-1], d[i]+f[ri[i]]);
        pre[i] = max(pre[i-1], d[i]+f[ri[i]]+maxx);
        maxx = max(maxx,f[ri[i]]-d[i]);
    }
    ans = pre[m];
    maxx = 0;
    for (int i = m; i >= 2; i--)
    {
        r[i] = max(r[i+1], d[m]-d[i]+f[ri[i]]);
        suf[i] = max(suf[i+1], f[ri[i]]-d[i]+maxx);
        maxx = max(maxx, f[ri[i]]+d[i]);
    }
    for (int i = 1; i < m; i++)
        ans = min(ans, max(pre[i], max(suf[i+1], l[i]+r[i+1]+d[1])));
    cout << max(ans, best);
    return 0;
}
