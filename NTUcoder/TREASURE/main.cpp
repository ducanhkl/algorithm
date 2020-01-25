#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

long long day[1001][1001], ans[1001][1001];
queue <pii> q;
int n, m, u1, v1, u2, v2;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool check(int x, int y)
{
    if (x <= 0 || y <= 0)
        return true;
    if (x > n || y > m)
        return true;
    return false;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        int x;
        cin >> x;
        day[i][j] = ans[i][j] = INT_MAX;
        if (x == 0)
            day[i][j] =  0, q.push({i, j});
    }
    cin >> u1 >> v1 >> u2 >> v2;
    while (q.size())
    {
        pii u = q.front();
        int x = u.first, y = u.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int X = dx[i] + x;
            int Y = dy[i] + y;
            if (check(X, Y))
                continue;
            if (day[X][Y] > day[x][y] + 1)
            {
                day[X][Y] = day[x][y] + 1;
                q.push({X, Y});
            }
        }
    }
    q.push({u1, v1});
    ans[u1][v1] = 0;
    while (q.size())
    {
        pii u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;
        for (int i = 0; i < 4; i++)
        {
            int X = dx[i] + x;
            int Y = dy[i] + y;
            if (check(X, Y))
                continue;
            if (ans[X][Y] > max(ans[x][y], day[X][Y]))
            {
                ans[X][Y] = max(ans[x][y],day[X][Y]);
                q.push({X, Y});
            }
        }
    }
    cout << ans[u2][v2];
    return 0;
}
