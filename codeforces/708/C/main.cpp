#include <bits/stdc++.h>
#define maxn 500000

using namespace std;

int sz[maxn], cnt[maxn], l[maxn], r[maxn], conti[maxn], tp[maxn];
int n, t, s;
vector <int> e[maxn];

void dfs1(int u, int par)
{
    sz[u] = 1;
    conti[u] = 0;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[conti[u]] < sz[v])
            conti[u] = v;
    }
}

void dfs2(int u, int par)
{
    tp[u] = t;
    sz[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs2(v, u);
        sz[u] += sz[v];
    }
}

bool check(int u)
{
    if (u == s)
        return true;
    int pos = tp[u];
    int m = n - sz[u] - max(l[pos-1], r[pos+1]);
    if (m <= n/2)
        return true;
    if (cnt[pos] == n/2 && n%2 == 0)
        return true;
    return false;
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
    dfs1(1, 0);
    int s = 1;
    while (sz[conti[s]] > n/2)
        s = conti[s];
    for (int i = 0; i < e[s].size(); i++)
    {
        t ++;
        int v = e[s][i];
        dfs2(v, s);
        cnt[t] = sz[v];
    }
    for (int i = 1; i <= t; i++)
        l[i] = max(l[i-1], cnt[i]);
    for (int i = t; i >= 1; i--)
        r[i] = max(r[i+1], cnt[i]);
    for (int i = 1; i <= n; i++)
        cout << (int)(check(i)) << " ";
    return 0;
}
