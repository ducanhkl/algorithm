#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;

int f[maxn][maxn][maxn], res[maxn][maxn][maxn];
int a[maxn][maxn];
int n, m;

int dx[] = {0, 1};
int dy[] = {1, 0};

bool check(int u, int v)
{
    return (u >= 1 && u <= n && v >= 1 && v <= m && a[u][v] != -1);
}

int dfs(int x,int y,int u,int v)
{
    if (f[x][y][u] == 1)
        return res[x][y][u];
    if (x == n && y == m)
    {
        f[x][y][u] = 1;
        return res[x][y][u] = a[x][y];
    }
    int p = a[x][y];
    if (x != u && y != v)
        p += a[u][v];
    res[x][y][u] = INT_MIN;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j  < 2; j++)
    {
        int newX = x + dx[i], newY = y + dy[i];
        int newU = u + dx[j], newV = v + dy[j];
        if (!check(newX, newY) || !check(newU, newV))
            continue;
        res[x][y][u] = max(res[x][y][u], dfs(newX, newY, newU, newV) + p);
    }
    f[x][y][u] = 1;
    return res[x][y][u];
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    memset(f, 0, sizeof(f));
    memset(a, 0 ,sizeof(a));
    for (int i = 1 ; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                a[i][j] = 1;
            }
            if (c == '#')
            {
                a[i][j] = -1;
            }
        }
    if (a[1][1] == '#')
        cout << -1;
    else
        cout << max(0, dfs(1, 1, 1, 1));
    return 0;
}
