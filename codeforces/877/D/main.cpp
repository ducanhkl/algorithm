#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define x first
#define y second
#define maxn 1004
using namespace std;
pii t, s;
queue <pii> q;
int d[maxn][maxn], m, n, k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char a[maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(d, 33, sizeof(d));
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
        for (int j =1; j <= m; j++)
            cin >> a[i][j];
    cin >> t.x >> t.y >> s.x >> s.y;
    q.push({t.x, t.y});
    d[t.x][t.y] = 0;
    while(!q.empty())
    {
        pii u = q.front();
        if (u == s)
            return printf("%d", d[s.x][s.y]), 0;
        for (int i = 0; i < 4; i++)
        {
            int dxx = dx[i], dyy = dy[i];
            for (int j = 1; j <= k; j++)
            {
                pii v;
                v.x = u.x + j*dxx;
                v.y = u.y + j*dyy;
                if (a[v.x][v.y] != '.'|| d[u.x][u.y] >= d[v.x][v.y])
                    break;
                if (d[u.x][u.y] + 1 < d[v.x][v.y]){
                    d[v.x][v.y] =  d[u.x][u.y] + 1;
                    q.push(v);
                }
            }
        }
        q.pop();
    }
    puts("-1");
	return 0;
}
