#include <bits/stdc++.h>
#define maxn 300

using namespace std;

int mark[maxn][maxn], dd[maxn][maxn];
int n, m, q, p, s, t;
int dy[] = {1, 1, -1, -1};
int dx[] = {-1, 1, 1, -1};

void init()
{
    for (int i = 0; i <= n+1; i++)
        mark[i][0] = mark[i][n+1] = mark[0][i] = mark[n+1][i] = 1;
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
        dd[i][j] = INT_MAX;
}

void bfs(int x, int y)
{
    dd[x][y] = 0;
    queue <pair <int, int> > v;
    v.push({x, y});
    while(!v.empty())
    {
        pair <int, int> k = v.front();
        v.pop();
        //cout << k.first << " " << k.second << endl;
        for (int i = 0; i < 4; i++)
        {
            bool check = true;
            //cout << k.first << " " << k.second << endl;
            for (int j = 1; j < 201 && check; j++)
            {
                int _x = k.first+dx[i]*j;
                int _y = k.second+dy[i]*j;
                int l = dd[k.first][k.second];
                if (mark[_x][_y] == 0 && dd[_x][_y] > l+1)
                {
                    dd[_x][_y] = l+1;
                    v.push({_x, _y});
                }
                if (mark[_x][_y] == 1)
                    check = false;
            }
        }
    }
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p >> q >> s >> t;
    init();
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        mark[x][y] = 1;
    }
    bfs(p, q);
    if (dd[s][t] == INT_MAX)
        cout << -1;
    else cout << dd[s][t];
    return 0;
}
