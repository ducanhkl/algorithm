#include <bits/stdc++.h>
#define maxn 1010
#define reset(a) memset(a, 0, sizeof(a))
#define pii pair <long double, int>

using namespace std;

int n, w;
long double e[maxn][maxn], dd[maxn], m;
struct point{
    long double x;
    long double y;
};
point p[maxn];

long double d(int x, int y)
{
    if (e[x][y] == 0)
        return 0;
    else
    return sqrt((p[x].x-p[y].x)*(p[x].x-p[y].x)+(p[x].y-p[y].y)*(p[x].y-p[y].y));
}
void dijkstra()
{
    priority_queue <pii> q;
    q.push({0, 1});
    while (q.size())
    {
        int u = q.top().second;
        long double w = -q.top().first;
        q.pop();
        if (w > e[1][u])
            continue;
        for (int i = 1; i <= n; i++)
            if (i != u)
        {
            int v = i;
            if (w + d(u,v) < dd[v])
                if (d(u,v) < m)
            {
                dd[v] = w + d(u, v);
                q.push({-dd[v], v});
            }
        }
    }
}
int main()
{
    reset(e), reset(p);
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            e[i][j] = INT_MAX;
    for (int i = 0; i < maxn; i++)
        dd[i] = INT_MAX;
    dd[1] = 0;
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> w;
    cin >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    for (int i = 1; i <= w; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u][v] = 0;
        e[v][u] = 0;
    }
    dijkstra();
    if (dd[n] == INT_MAX)
        cout << -1; else
    cout <<(long long)(dd[n]*1000);
    return 0;
}
