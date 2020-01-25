#include <bits/stdc++.h>
#define maxn 82
#define maxc 123456789

using namespace std;

vector <pair<int, int> > e[maxn];
int d[maxn][maxn][maxn][maxn];
int ans = maxc;

int dfs(int u, int l, int r, int k)
{
    int res = maxc;
    if (k == 1)
        return d[u][l][r][k] = 0;
    if (d[u][l][r][k] != -1)
        return d[u][l][r][k];
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].first;
        int w = e[u][i].second;
        if (v >= l && v <= r)
            if (v < u)
                res = min(res, dfs(v, l, u-1, k-1)+w);
            else
                res = min(res, dfs(v, u+1, r, k-1)+w);
    }
    return d[u][l][r][k] = res;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            for (int k = 0; k < maxn; k++)
                for (int h = 0; h < maxn; h++)
                    d[i][j][k][h] = -1;
    ios_base::sync_with_stdio(false);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
        ans = min(ans, dfs(i, 1, n, k));
    if (ans == maxc)
        cout << -1;
    else cout << ans;
    return 0;
}
