#include <bits/stdc++.h>
#define maxn 1006

using namespace std;

vector <int> e[maxn];
int counter = 0, n, m, k = 0;
stack <int> t;
int num[maxn], low[maxn], d[maxn], f[maxn];

int visit(int u)
{
    t.push(u);
    counter ++;
    num[u] = counter;
    low[u] = counter;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (d[v] != 0)
            continue;
        if (num[v] == 0)
        {
            visit(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u])
    {
        k ++;
        int v;
        do
        {
            v = t.top();
            d[v] = k;
            t.pop();
        } while(v!=u);
        f[k] = 1;
    }
    return 0;
}

int tarjan()
{
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; i++)
            if (!num[i])
                visit(i);
}
int solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < e[i].size(); j ++)
            if (d[i] != d[e[i][j]])
                f[d[e[i][j]]] = 0;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    tarjan();
    solve();
    int ans = 0;
    for (int i = 1; i <= k; i++)
        if (f[i])
            ans ++;
    cout << ans;
}
