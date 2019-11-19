#include "bits/stdc++.h"

using  namespace std;

int dx[]={-1,0,1,0},
    dy[]={0,1,0,-1};
const int maxn = 1e3+100;

int n, m;
int h[maxn][maxn], a[maxn][maxn];
long long ans = 0;
vector < pair <int, int> > e[1000800];

void bfs(int x, int y, int val)
{
    h[x][y] = val;
    deque < pair <int, int> > q;
    q.push_back({x, y});
    while (q.size())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop_front();
        for (int i = 0; i  < 4; i++)
        {
            int nx = xx+dx[i];
            int ny = yy+dy[i];
            if (!h[nx][ny] && a[nx][ny] <= val)
            {
                h[nx][ny] = val;
                q.push_back({nx, ny});
            }
        }
    }
    return ;
}

bool isBorder(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        if (h[x+dx[i]][y+dy[i]])
            return  1;
    }
    return 0;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        h[i][0] = h[i][m+1] = 1;
    for (int i = 1; i <= m; i++)
        h[0][i] = h[n+1][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            e[a[i][j]].push_back({i, j});
        }
    for (int i = 1; i <= 1e6+10; i++)
    {
        for (auto v : e[i])
        {
            if (h[v.first][v.second] == 0 && isBorder(v.first, v.second))
                bfs(v.first, v.second, a[v.first][v.second]);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            ans += max(0, h[i][j] - a[i][j]);
        }
    cout << ans;
}