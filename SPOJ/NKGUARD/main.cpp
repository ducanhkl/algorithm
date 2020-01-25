#include <bits/stdc++.h>
#define maxn 1006
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

int a[maxn][maxn], dd[maxn][maxn], ans[maxn*maxn];
int xx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int yy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, res = 0, dem = 0;

void bfs(pair<int, int> x)
{
    dd[x.first][x.second] = dem;
    queue <pair<int, int> > t;
    t.push(x);
    while (!t.empty())
    {
        pair <int, int> u;
        u = t.front();
        t.pop();
        for (int i = 0; i < 8; i++)
        {
            int x = u.first + xx[i];
            int y = u.second + yy[i];
            if (dd[x][y] == 0 && a[u.first][u.second] >= a[x][y])
                dd[x][y] = dem, t.push(make_pair(x, y));
        }
    }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    reset(a), reset(dd), reset(ans);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 0; i <= n; i++)
        dd[i][0] = dd[i][m+1] = -1;
    for (int i = 1; i <= m; i++)
        dd[0][i] = dd[n+1][i] = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (dd[i][j] == 0)
                {
                    dem ++;
                    bfs(make_pair(i, j));
                }
    dem = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans[++dem] = dd[i][j];
    sort(ans + 1, ans + dem +1);
    res = 1;
    for (int i = 2; i <= dem; i++)
        if (ans[i] != ans[i-1])
            res ++;
    cout << res;
    return 0;
}
