#include <bits/stdc++.h>

using namespace std;

const int maxc = 1e4+100;
const int maxn = 800;

int a[maxn][maxn], visit[maxn][maxn];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, ans = 0;

vector<pair <int, int>> check_list[maxc];


void dfs(int x, int y)
{
    visit[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int new_x = x+dx[i];
        int new_y = y+dy[i];
        if (!visit[new_x][new_y] && a[x][y] >= a[new_x][new_y])
        {
            dfs(new_x, new_y);
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            check_list[a[i][j]].push_back({i, j});
        }
    for (int i = 0; i <= n+1; i++)
        visit[i][0] = visit[i][m+1] = 1;
    for (int i = 0; i <= m+1; i++)
        visit[0][i] = visit[n+1][i] = 1;
    for (int i = maxc-1; i >= 1; i--)
    {
        for (auto p : check_list[i])
        {
            if (!visit[p.first][p.second])
            {
                ans ++;
                dfs(p.first, p.second);
            }
        }
    }
    cout << ans;
    return 0;
}
