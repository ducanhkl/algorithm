#include <bits/stdc++.h>
#define maxn 300006

using namespace std;

int n;
long long val[maxn], cnt[maxn], dif[maxn];
const long long mod = 1e9+7;
long long ans = 0;
vector <int> e[maxn];

void dfs1(int u, int par)
{
    cnt[u] = dif[u] = 1;
    ans = (ans+val[u]*n)%mod;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs1(v, u);
        cnt[u] += cnt[v];
        dif[u] -= dif[v];
        ans = (ans+val[u]*-dif[v]%mod*(n-cnt[v])%mod)%mod;
    }
    return ;
}

void dfs2(int u, int par, long long trc)
{
    ans = (ans+val[u]*trc%mod*cnt[u]%mod)%mod;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs2(v, u, -(trc+dif[u]+dif[v]));
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    cout << (ans+mod*mod)%mod;
}
