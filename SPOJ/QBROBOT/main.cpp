#include <bits/stdc++.h>
#define maxn 600

using namespace std;


struct edge
{
    int v;
    long long t; long long c;
    edge (int _v, unsigned long long _t, long long _c)
    {
        v = _v;
        t = _t;
        c = _c;
    }
};
vector <edge> e[maxn];
int n, m, res = 0, limit;
unsigned long long changer[maxn], d1[maxn], d2[maxn], fr[maxn];

void loadgrape()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> changer[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, t, c;
        cin >> u >> v >> t >> c;
        e[u].push_back(edge(v, t, c));
        e[v].push_back(edge(u, t, c));
    }
    return;
}

void ijk(int x, unsigned long long *d)
{
    priority_queue < pair<int, int> > q;
    q.push({0, x});
    for (int i = 0; i < maxn; i++)
        d[i] = LONG_LONG_MAX;
    d[x] = 0;
    while (q.size())
    {
        int u = q.top().second;
        int l = -q.top().first;
        q.pop();
        if (d[u] < l)
            continue;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].v;
            int w = e[u][i].t;
            if (w + l < d[v])
                {
                    d[v] = w+l;
                    q.push({-d[v], v});
                }
        }
    }
    return;
}

bool check(int u, int t, long long w)
{
    if (changer[u])
        w = limit;
    if (u == n)
        return true;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].v;
        int l = e[u][i].t;
        int c = e[u][i].c;
        if (t + d2[v] + l == d1[n] && w - c >= 0 && check(v, t+l, w-c))
            return true;
    }
    return false;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    loadgrape();
    ijk(1, d1);
    ijk(n, d2);
    long long l = 0, r = 1e9;
    while (r >= l)
    {
        int mid = (r+l)>>1;
        limit = mid;
        if (check(1, 0, mid))
            res = mid, r = mid - 1;
        else l = mid+1;
    }
    cout << res;
    return 0;
}
