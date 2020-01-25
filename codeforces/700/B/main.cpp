#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

#define ll long long

ll n, k, dd[maxn], ans =0;
vector <int> e[maxn];

int dfs(int u, int par = 1)
{
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs(v, u);
        dd[u] += dd[v];
        ans += min(dd[v], 2*k-dd[v]);
    }
    return 0;
}

int main()
{
    int x; memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= 2*k; i++)
        cin >> x, dd[x] = 1;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    cout << ans;
    return 0;
}
