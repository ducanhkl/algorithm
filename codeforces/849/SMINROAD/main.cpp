#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006

using namespace std;

struct edge{
    ll x, y, w;
} e[maxn];
int a[maxn], n, m, dj[maxn];
ll kq = 0;
bool cmp(edge _x, edge _y)
{
    return _x.w>_y.w;
}

int j(int _x)
{
    if (dj[_x] < 0)
        return _x;
    return dj[_x] = j(dj[_x]);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        cin >> e[i].x >> e[i].y;
        e[i].w = min(a[e[i].x],a[e[i].y]);
    }
    sort(e, e+m, cmp);
    memset(dj, -1, sizeof(dj));
    for (int i = 0; i < m; i++)
    {
        int u = j(e[i].x);
        int v = j(e[i].y);
        if (u != v)
        {
            kq += dj[u]*dj[v]*e[i].w*2;
            dj[u] += dj[v];
            dj[v] = u;
        }
    }
    cout << kq;
	return 0;
}
