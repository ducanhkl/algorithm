#include <bits/stdc++.h>
#define maxn 700

using namespace std;

int n, m;
long long d[maxn][maxn], ans[maxn][maxn], res[maxn][maxn], e[maxn][maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    memset(ans, 0, sizeof(ans));
    memset(res, 0, sizeof(res));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            d[i][j] = d[j][i] = e[i][j] = e[j][i] = INT_MAX;
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
        e[u][v] = e[v][u] = w;
    }
    for (int i = 1; i <= n; i++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                d[u][v] = min(d[u][v], d[u][i]+d[i][v]);
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            for (int i = 1; i <= n; i++)
                    if (v != i)
                        if (d[u][v] == d[u][i] + e[i][v] && d[u][v] < INT_MAX)
                            res[u][v]++;
    for (int u = 1; u <= n; u++)
        for (int v = u+1; v <= n; v++)
            for (int i = 1; i <= n; i++)
                if (d[u][v] == d[u][i]+d[i][v] && d[u][v] < INT_MAX)
                    ans[u][v] += res[u][i];
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            if (i != j)
                cout << ans[i][j] << " ";
    return 0;
}
