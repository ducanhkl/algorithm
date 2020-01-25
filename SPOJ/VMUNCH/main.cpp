#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 120
using namespace std;

struct data
{
    int x; int y;
};
queue <data> q;
int c[maxn][maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        char x;
        cin >> x;
        if (x == 'C')
            q.push({i, j});
        if (x == '*')
            c[i][j] = -1;
    }
    for (int i = 1; i <= n; i++)
        c[i][0] = c[i][m+1] = -1;
    for (int i = 1; i <= m; i++)
        c[0][i] = c[n+1][i] = -1;
    while (!q.empty())
    {
        data u = q.front();
        q.pop();
        if (u.x == 1 && u.y ==1)
            return cout << c[1][1], 0;
        for (int i = 0; i < 4;i++)
            {
                data v;
                v.x = u.x + dx[i];
                v.y = u.y + dy[i];
                if (!c[v.x][v.y])
                {
                    c[v.x][v.y] = c[u.x][u.y] + 1;
                    q.push(v);
                }
            }
    }
	return 0;
}
