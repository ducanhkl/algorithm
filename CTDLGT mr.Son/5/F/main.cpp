#include <bits/stdc++.h>

using namespace std;

const int maxn = 120;
typedef pair <int, int> ii;
typedef pair <int,ii> pii;
int n;
int a[maxn][maxn], dd[maxn][maxn];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i <= n+1; i++)
        a[i][0] = a[i][n+1] = a[0][i] = a[n+1][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            if (x == '.')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= n+1; j++)
            dd[i][j] = INT_MAX;
    priority_queue <pii> q;
    int x, y, z, t;
    cin >> x >> y >> z >> t;
    x ++, y ++, z++, t++;
    q.push({0, {x, y}});
    while (q.size())
    {
        int l = -q.top().first;
        ii u = q.top().second;
        q.pop();
        if (dd[u.first][u.second] < l)
            continue;
        dd[u.first][u.second] = l;
        for (int i = 0; i < 4; i ++)
        {
            int xx = u.first+dx[i], yy = u.second+dy[i];
            while (dd[xx][yy] > l+1 && a[xx][yy] == 0)
            {
                dd[xx][yy] = l+1;
                q.push({-dd[xx][yy], {xx, yy}});
                xx += dx[i];
                yy += dy[i];
            }
        }
    }
    cout << dd[z][t];
    return 0;
}
