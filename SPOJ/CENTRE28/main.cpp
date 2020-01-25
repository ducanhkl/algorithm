#include <bits/stdc++.h>
#define maxn 40000

using namespace std;

int n, m;
long long d1[maxn], d2[maxn], g1[maxn], g2[maxn];
const long long maxc = 1e8;
vector <pair<int, int> > e[maxn];
int ans = 0;

void ijk(int f, long long *d, long long *g)
{
    for (int i = 0; i < maxn; i++)
        d[i] = maxc, g[i] = 0;
    g[f] = 1, d[f] = 0;
    priority_queue <pair<int, int> > q;
    q.push({0, f});
    while(q.size())
    {
        int u = q.top().second;
        int l = -q.top().first;
        q.pop();
        if (d[u] < l)
            continue;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].first;
            int w = e[u][i].second;
            if (d[u]+w < d[v])
            {
                d[v] = d[u]+w;
                g[v] = g[u];
                q.push({-d[v], v});
                continue;
            }
            if (d[u]+w == d[v])
                g[v] += g[u];
        }
    }
}

int main()
{
    //freopen("inp.ttx", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    ijk(1, d1, g1);
    ijk(n, d2, g2);
    for (int i = 1; i <= n; i++)
        if (d1[i] + d2[i] > d1[n] || (d1[i]+d2[i] == d1[n] && g1[i]*g2[i] < g1[n]))
            ans ++;
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (d1[i] + d2[i] > d1[n] || (d1[i]+d2[i] == d1[n] && g1[i]*g2[i] < g1[n]))
            cout << i << endl;
    return 0;
}
