#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+100;

typedef pair <int, int> pii;

int n, m;
int d[maxn][maxn], a[maxn][maxn];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve()
{
    for (int i = 0; i <= n+1; i++)
        d[i][0] = d[i][m+1] = a[i][0] = a[i][m+1] = -1;
    for (int i = 0; i <= m+1; i++)
        d[0][i] = d[n+1][i] = a[0][i]= a[n+1][i] = -1;
    queue<pii> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int f = 0;
            for (int k = 0; k < 4; k++)
            {
                int new_i = i + dx[k];
                int new_j = j + dy[k];
                if (a[i][j] == a[new_i][new_j])
                    f = 1;
            }
            if (f == 1)
            {
                d[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    while (q.size())
    {
        pii u = q.front();
        for (int k = 0; k < 4; k++)
        {
            int new_i = u.first + dx[k];
            int new_j = u.second + dy[k];
            if (d[new_i][new_j] == 0)
            {
                d[new_i][new_j] = d[u.first][u.second]+1;
                q.push({new_i, new_j});
            }
        }
        q.pop();
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int t;
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        char c;
        cin >> c;
        c -= '0';
        a[i][j] = c;
    }
    solve();
    while (t--)
    {
        long long  x, y, p;
        cin >> x >> y >> p;
        if (d[x][y] > p || d[x][y] == 0)
        {
            cout << a[x][y];
        } else
        {
            if ((p - (long long)d[x][y] + 1LL)%2 == 0)
                cout << a[x][y];
            else
                cout << !a[x][y];
        }
        cout << endl;
    }
    return 0;
}
