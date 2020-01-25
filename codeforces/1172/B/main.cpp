#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
const int mod = 998244353;
long long f[maxn], g[maxn];
int n;
vector <int> e[maxn];

void dfs(int u, int par)
{
    f[u] = e[u].size();
    f[u] = g[f[u]];
    for (auto v: e[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
        f[u] = (f[u]*f[v])%mod;
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    g[0] = 1;
    for (int i = 1; i  < maxn; i++)
        g[i] = (g[i-1]*i)%mod;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    //cout << e[2].size() << endl;
    dfs(1, 1);
    cout << f[1]*n%mod;
    return 0;
}
