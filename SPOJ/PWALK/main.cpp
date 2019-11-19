#include <bits/stdc++.h>
#define pii pair <int, long long >
#define re(a) memset(a, 0, sizeof(a));
#define maxn 1010

using namespace std;

int n, q, d[maxn], root[maxn];
long long ans[maxn];
vector <pii> e[maxn];


void dfs(int u)
{
    for (int i = 0; i < e[u].size(); i++)
        if (e[u][i].first != root[u])
    {
        int v = e[u][i].first;
        root[v] = u;
        d[v] = d[u]+1;
        ans[v] = e[u][i].second;
        dfs(v);
    }
    return;
}
long long res(int u, int v)
{
    long long RES = 0;
    #define up(u) RES += ans[u], u = root[u]
    while (d[u] > d[v])
        up(u);
    while (d[v] > d[u])
        up(v);
    while (u != v)
        up(u), up(v);
    return RES;

}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1);
    while(q--)
    {
        int u, v;
        cin >> u >> v;
        cout << res(u, v) << endl;
    }
    return 0;
}
