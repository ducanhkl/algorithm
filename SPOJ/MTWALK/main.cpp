#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int n, a[maxn][maxn];
int dd[maxn][maxn];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void bfs(int minx, int maxx)
{
    queue <pair<int, int> > t;
    t.push(make_pair(1, 1));
    dd[1][1] = 1;
    while(!t.empty())
    {
        pair <int, int> u = t.front();
        t.pop();
        int x = u.first;
        int y = u.second;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + dx[i];
            int _y = y + dy[i];
            if (a[_x][_y] >= minx && a[_x][_y] < maxx  && dd[_x][_y] == 0)
            {
                dd[_x][_y] = 1;
                t.push(make_pair(_x, _y));
            }
        }
    }
}
void reset()
{
    memset(dd, 0, sizeof(dd));
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 0; i <= 110; i++)
        for (int j = 0; j <= 110-i; j++)
    {
        if (i == 2)
            int k = 1;
        reset();
        bfs(j, j+i);
        if (dd[n][n])
            {
                cout << i;
                return 0;
            }
    }
    return 0;
}
