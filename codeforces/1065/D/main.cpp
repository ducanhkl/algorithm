#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;
const long long maxn = 310, inf = 1e9;
int n;
int a[maxn][maxn];
pii dis[400][400], pos[maxn], dp[maxn][maxn];

int dx[] = {0, -2, -1, 1, 2,  2,  1, -1, -2};
int dy[] = {0, 1,  2, 2, 1, -1, -2, -2, -1};
int get(int x, int y, int z)
{
    return x*(n+1)*3+y*3+z;
}
int check(int x, int y)
{
    return (x > 0 && x <= n && y > 0 && y <= n);
}
pii operator + (pii x, pii y)
{
    return {x.first + y.first, x.second+y.second};
}
void init()
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            dis[i][j] = {inf, inf};
    for (int i = 0; i < maxn; i++)
        dis[i][i] = {0, 0};
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int k = 1; k <= 8; k++)
            {
                int nx = dx[k] + x;
                int ny = dy[k]+y;
                if (!check(nx, ny))
                    continue;
                dis[get(x, y, 0)][get(nx, ny, 0)] = {1, 0};
            }
            for (int i = -n; i <= n; i++)
            {
                int nx = x + i;
                int ny = y + i;
                if (check(nx, ny))
                    dis[get(x, y, 1)][get(nx, ny, 1)] = {1, 0};
                ny = y-i;
                if (check(nx, ny))
                    dis[get(x, y, 1)][get(nx, ny, 1)] = {1,0 };
            }
            for (int i = 1; i <= n; i++)
            {
                int nx = x;
                int ny = i;
                dis[get(x, y, 2)][get(nx, ny, 2)] = {1, 0};
                nx = i;
                ny = y;
                dis[get(x, y, 2)][get(nx, ny, 2)] = {1, 0};
            }
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                {
                    if (i != j)
                        dis[get(x, y, i)][get(x, y, j)] = {1, 1};
                }
        }
    }
    for (int k = 1; k < maxn; k++)
        for (int i = 1; i < maxn; i++)
            for (int j = 1; j < maxn; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    return ;
}
void solve()
{
    for (int i = 0; i <= n*n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = {inf, inf};
    dp[1][0] = dp[1][1] = dp[1][2] = {0, 0};
    for (int i = 1; i < n*n; i++)
    {
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
            {
                dp[i+1][k] = min(dp[i+1][k], dp[i][j] + dis[get(pos[i].first, pos[i].second, j)][get(pos[i+1].first, pos[i+1].second, k)]);
            }
    }
    pii ans = {inf, inf};
    ans = min(ans, min(dp[n*n][0], min(dp[n*n][1], dp[n*n][2])));
    cout << ans.first << " " << ans.second;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            pos[a[i][j]] = {i, j};
        }
    init();
    solve();
    return 0;
}
