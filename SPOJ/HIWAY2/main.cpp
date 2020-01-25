#include <bits/stdc++.h>
#define maxn 50040

using namespace std;

int m, n, s, f;
vector <pair<int, long long> > e[maxn];
map <int, int> dis[maxn];
long long d[maxn];
int ufr[maxn], tr[maxn];
const long long maxc = 1e15;
long long ans = 0;

void ijk(int x)
{
    priority_queue <pair<long long, int>> q;
    q.push(make_pair(0, x));
    while (q.size())
    {
        int u = q.top().second;
        long long l = -q.top().first;
        q.pop();
        if (d[u] < l)
            continue;
        ufr[u] = 1;
        if (u == f)
            return ;
        for (int i = 0; i < (int)e[u].size(); i++)
            {
                int v = e[u][i].first;
                int w = e[u][i].second;
                if (d[u]+w < d[v] && dis[u][v] == 0)
                {
                    d[v] = d[u]+w;
                    tr[v] = u;
                    q.push(make_pair(-d[v], v));
                }
            }
    }
}

void trace()
{
    int u = f;
    while (u != s)
    {
        int v = tr[u];
        dis[u][v] = dis[v][u] = 1;
        u = tr[u];
    }
    return ;
}

void solve()
{
    for (int i = 0; i < maxn; i++)
        d[i] = maxc, ufr[i] = 0;
    d[s] = 0;
    ijk(s);
    if (ufr[f] == 0)
        return cout << -1, (void)0;
    ans += d[f];
    trace();
    for (int i = 0; i < maxn; i++) d[i] = maxc, ufr[i] = 0;
    d[s] = 0;
    ijk(s);
    if (ufr[f] == 0)
        return cout << -1, (void)0;
    ijk(s);
    ans += d[f];
    cout << ans;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s >> f;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back(make_pair(v, w));
        e[v].push_back(make_pair(u, w));
    }
    solve();
    return 0;
}
