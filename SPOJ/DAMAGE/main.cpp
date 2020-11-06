#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5+100;

int n, m, q, ck[maxn], dmg[maxn];
vector <int> e[maxn];
int ans = 0;

void dfs(int u)
{
    ck[u] = 1;
    ans --;
    for (auto v: e[u])
    {
        if (dmg[v] || ck[v])
            continue;
        dfs(v);
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin  >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >>u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans = n;
    for (int i = 1; i <= q; i++)
    {
        int u;
        cin >> u;
        for (auto v: e[u])
        {
            dmg[v] = 1;
        }
    }
    dfs(1);
    cout << ans;
    return 0;
}
