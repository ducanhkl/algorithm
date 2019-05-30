#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 10004

using namespace std;

int a[maxn][maxn], d[maxn][maxn], n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int ijk()
{
    queue <pii> q;
    if (a[1][1] == 0)
        d[1][1] = 1;
    else d[1][1] = 0;
    q.push({1, 1});
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            int l = d[x][y] + 1;
            l = l +  (l + a[xx][yy] +1)%2;
            if (xx <= n && xx > 0 && yy <= m && yy > 0)
                if (l < d[xx][yy])
            {
                d[xx][yy] = l;
                q.push({xx, yy});
            }
        }
    }
}
int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                d[i][j] = 1e9+7;
            }
    ijk();
    cout << d[n][m];
	return 0;
}
