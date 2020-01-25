#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int dd[maxn], n, m, s, t, d1[maxn], d2[maxn];
long long ans = 0, res, sl = 0;
vector <int> e[maxn];
int c[maxn][maxn];

void ijk(int _s, int *d)
{
    for (int i = 0; i < maxn; i++) d[i] = 123456789;
    d[_s] = 0;
    priority_queue <pair <int, int> > q;
    q.push({0, _s});
    while (q.size())
    {
        int u = q.top().second;
        int w = -q.top().first;
        q.pop();
        if (d[u] < w)
            continue;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i];
            if (w + 1 < d[v])
            {
                d[v] = w + 1;
                q.push({-d[v], v});
            }
        }
    }
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    memset(c, 0, sizeof(c));
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m;  i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        c[u][v] = c[v][u] = 1;
    }
    ijk(s, d1);
    ijk(t, d2);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
    {
        int dd1 = d1[i] + d2[j] + 1;
        int dd2 = d1[j] + d2[i] + 1;
        if (!(dd1 < d1[t] || dd2 < d1[t]) && c[i][j] != 1)
            ans ++;
    }
    cout << ans;
    return 0;
}
