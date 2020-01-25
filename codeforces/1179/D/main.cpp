#include <bits/stdc++.h>

using namespace std;

const long long maxn = 5e5+100;
vector <int> e[maxn];
long long  n;
int umax = 0;
long long sz[maxn], ans[maxn];

void dfs1(int u, int par)
{
    sz[u] = 1;
    for (auto v: e[u])
    {
        if (v == par)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int par)
{
    if (ans[u] > ans[umax])
        umax = u;
    for (auto v: e[u])
    {
        if (v == par)
            continue;
        ans[v] = ans[u] + (sz[u]-sz[v])*sz[v];
        dfs2(v, u);
    }
}

void calc(int u)
{
    dfs1(u, 0);
    ans[u] = 0;
    dfs2(u, 0);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >>u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    calc(1);
    calc(umax);
    cout << ans[umax] + n*(n-1)/2;
    return 0;
}
