#include <bits/stdc++.h>
#define maxn 5001

using namespace std;

int n, b;
long long c[maxn], d[maxn], f[maxn][maxn], g[maxn][maxn];
int sl[maxn];
vector <int> e[maxn];


void dfs(int u)
{
    g[u][0] = 0;
    g[u][1] = c[u];
    f[u][1] = c[u]  - d[u];
    sl[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == 6)
            n = n;
        dfs(v);
        for (int j = sl[u]; j >= 0; j--)
            for (int k = 0; k <= sl[v]; k++)
                {
                    g[u][j+k] = min(g[u][j+k], g[u][j] + g[v][k]);
                    f[u][j+k] = min(f[u][j+k], min(f[u][j]+g[v][k], f[u][j]+f[v][k]));
                }
        sl[u] += sl[v];
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            f[i][j] = g[i][j] = INT_MAX;
    ios_base::sync_with_stdio(false);
    cin >> n >> b;
    cin >> c[1] >> d[1];
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> c[i] >> d[i] >> u;
        e[u].push_back(i);
    }
    dfs(1);
    for (int i = n; i >= 1; i--)
        if (min(f[1][i], g[1][i]) <= b)
            return cout << i, 0;
    cout << 0;
    return 0;
}
