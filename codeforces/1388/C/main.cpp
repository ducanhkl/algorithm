#include <bits/stdc++.h>

using namespace std;

int const maxn = 1e5+100;
int n, m;
int h[maxn], g[maxn], p[maxn];
vector <int> e[maxn];
int res;

void dfs(int u, int par)
{
    g[u] = 0;
    int ans = 0;
    for (auto v : e[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
        ans += g[v];
        p[u] += p[v];
    }
    if (abs((p[u] + h[u])%2) == 1)
    {
        res = 1;
        return;
    }
    g[u] = (p[u] + h[u])/2;
    if (g[u] < ans || g[u] < 0 || g[u] > p[u])
    {
        res = 1;
    }
}

void solve()
{
    res = 0;
    dfs(1, 0);
    if (res == 1)
        cout << "NO";
    else
        cout << "YES";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test --)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            e[i].resize(0);
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        solve();
    }
    return 0;
}
