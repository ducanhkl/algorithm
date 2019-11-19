#include <bits/stdc++.h>
#define maxn 123460

using namespace std;


int ans = 0, n, m, w;
int mark[maxn], dd[maxn];
vector <int> e[maxn];


int dfs(int u, int par)
{
    dd[u] = dd[par]+1;
    if (dd[w] < dd[u] && mark[u])
        w = u;
    if (dd[w] == dd[u] && mark[u])
        w = min(w, u);
    int res = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        res += dfs(v, u);
    }
    if (res == 1 && !mark[u])
        return 0;
    else return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int x;
    memset(dd, 0, sizeof(dd));
    memset(mark, 0, sizeof(mark));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        mark[x] = 1;
    }
    w = x;
    ans = dfs(x, x);
    memset(dd, 0, sizeof(dd));
    x = w;
    dfs(w, w);
    x = min(w, x);
    cout << x << endl << ans*2 - 1 - dd[w];// << endl << w;
    return 0;
}
