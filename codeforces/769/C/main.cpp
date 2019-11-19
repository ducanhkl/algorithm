#include <bits/stdc++.h>
#define maxn 1006
#define maxc 123456789

using namespace std;

string s = "DLRU", ans = "";
int n, m, k, xx, yy;
char a[maxn][maxn];
int dd[maxn][maxn];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

int main()
{
    //freopen("inp.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%s", a[i]+1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        dd[i][j] = maxc;
        if (a[i][j] == 'X')
            a[i][j] = '.', xx = i, yy = j, dd[i][j] = 0;
    }
    queue <pair<int, int> > q;
    q.push({xx, yy});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int _x = x + dx[i];
            int _y = y + dy[i];
            if (dd[x][y] + 1 < dd[_x][_y] && a[_x][_y] == '.' && _x > 0 && _y > 0 && _x <= n && _y <= m)
            {
                dd[_x][_y] = dd[x][y] + 1;
                q.push({_x, _y});
            }
        }
    }
    for (int i = 1; i <= k; i++)
        {
            bool ckpoint = true;
            for (int j = 0; j < 4; j++)
            {
                int x = xx+dx[j];
                int y = yy+dy[j];
                if (a[x][y] == '.' && dd[x][y] <= k-i && x > 0 && y > 0 && x <= n && y <= m)
                {
                    ans = ans + s[j];
                    xx = x;
                    yy = y;
                    ckpoint = false;
                    break;
                }

            }
            if (ckpoint)
                return cout << "IMPOSSIBLE", 0;
        }
    cout << ans;
    return 0;
}
