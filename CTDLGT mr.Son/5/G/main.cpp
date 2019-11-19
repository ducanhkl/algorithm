#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> pii;
const int maxn = 600;

int n, m, a[maxn][maxn], dd[maxn][maxn];
priority_queue <pii> q;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        cin >> a[i][j];
        if (a[i][j] == 2)
            dd[i][j] = 0, q.push({0, {i, j}});
        else
            dd[i][j] = INT_MAX;
    }
    while (q.size())
    {
        int l = -q.top().first;
        ii u = q.top().second;
        q.pop();
        if (l < dd[u.first][u.second])
            continue;
        dd[u.first][u.second] = l;
        for (int i = 0; i < 4; i++)
        {
            int xx = u.first + dx[i], yy = u.second + dy[i];
            if (xx < 1 || yy < 1 || xx > n || yy > m)
                continue;
            if (dd[xx][yy] <= l+1 || a[xx][yy] == 0)
                continue;
            dd[xx][yy] = l+1;
            q.push({-dd[xx][yy], {xx, yy}});
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1 && dd[i][j] == INT_MAX)
                return cout << -1, 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1)
                ans = max(ans, dd[i][j]);
    cout << ans;
    return 0;
}
