#include <bits/stdc++.h>
#define maxn 300005

using namespace std;

int n, m, ck = 0, cnt = 0, cnt1 = 0;
int dd[maxn], d[maxn], ans[maxn];
vector <pair<int, int> > e[maxn];

void dfs(int u)
{
    dd[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].first;
        int w = e[u][i].second;
        if (dd[v] == 0)
        {
            dfs(v);
            if (d[v])
                ans[++cnt] = w, d[u] = !d[u];
        }
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        if (d[i] == -1)
            d[i] = 0, ck = i;
        if (d[i] == 1)
            cnt1 ++;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    if (cnt1&1 && ck == 0)
        return cout << -1, 0;
    if (cnt1&1)
        d[ck] = 1;
    dfs(1);
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++)
        cout << ans[i] << " ";
    return 0;
}
