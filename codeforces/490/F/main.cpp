#include <bits/stdc++.h>
#define maxn 7000

using namespace std;

int n;
int r[maxn], t[maxn], ans = 0;
vector <int> e[maxn];

void dfs(int u, int par)
{
    int pos = lower_bound(t+1, t+n+1, r[u])-t;
    int last = t[pos];
    t[pos] = r[u];
    ans = max(ans, pos);
    if (ans == 7)
        n = n;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs(v, u);
    }
    t[pos] = last;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            t[j] = INT_MAX;
        dfs(i, 0);
    }
    cout << ans;
    return 0;
}
