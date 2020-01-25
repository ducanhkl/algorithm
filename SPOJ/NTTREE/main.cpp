#include <bits/stdc++.h>
#define maxn 10010

using namespace std;


int n;
long long ans = 0, dd[maxn], fr[maxn], l[maxn];
vector <pair<int, long long> > e[maxn];

void dfs(int u)
{
    if (!fr[u])
        return;
    fr[u] = 0;
    for (int i = 0; i < e[u].size(); i++)
        if (fr[e[u][i].first])
    {
        int v = e[u][i].first;
        dfs(v);
        l[u] += e[u][i].second*dd[v] + l[v];
        dd[u] += dd[v];
    }
}

void dfs1(int u, long long cp)
{
    if (!fr[u])
        return;
    fr[u] = 0;
    ans += cp;
    for (int i = 0; i < e[u].size(); i++)
        if (fr[e[u][i].first])
            dfs1(e[u][i].first, cp + e[u][i].second*(n-2*dd[e[u][i].first]));
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n-1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    memset(l, 0, sizeof(l));
    for (int i = 0; i <= n; i++)
        dd[i] = 1, fr[i] = 1;
    dfs(0);
    for (int i = 0; i <= n; i++)
        fr[i] = 1;
    dfs1(0, l[0]);
    cout << ans/2;
    return 0;
}
