#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+100;
const long long maxc = 1e18;
typedef pair <int, int> pii;
int n, m;
long long res[maxn][maxn], a[maxn][maxn];
int dx[] = {0, 0, 1, 1}, dy[] = {-1, 1, 1, 0};

void reset()
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            res[i][j] = a[i][j] = maxc;
    return ;
}

bool check(int x, int y)
{
    return (x > 0 && y > 0 && x <= n && y <= m);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        reset();
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        priority_queue <pair <long long, pii> > q;
        q.push({-a[1][1], {1, 1}});
        while (q.size())
        {
            pair <long long, pii> u = q.top();
            q.pop();
            pair <int, int> p = u.second;
            long long l = -u.first;
            if (l > res[p.first][p.second])
                continue;
            res[p.first][p.second] = l;
            for (int i = 0; i < 4; i++)
            {
                int xx = p.first + dx[i];
                int yy = p.second + dy[i];
                if (check(xx, yy) && l + a[xx][yy] < res[xx][yy])
                {
                    res[xx][yy] = l + a[xx][yy];
                    q.push({-res[xx][yy], {xx, yy}});
                }
            }
        }
        cout << res[n][m] << endl;
    }
    return 0;
}
