#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

int n, m, l, s, t;
long long d[maxn], v[maxn], u[maxn], w[maxn];
vector <pair <int, long long> > e[maxn];


void ijk()
{
    for (int i = 0; i < n; i++)
        d[i] = INT_MAX;
    d[s] = 0;
    priority_queue <pair<int, long long> > q;
    q.push({0, s});
    while(q.size())
    {
        int u = q.top().second;
        int ll = -q.top().first;
        q.pop();
        if (d[u] < ll)
            continue;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].first;
            int l1 = e[u][i].second;
            if (l1 + d[u] < d[v])
            {
                d[v] = l1 + d[u];
                q.push({-d[v], v});
            }
        }
    }
    return;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(u, 0, sizeof(u));
    memset(v, 0, sizeof(s));
    memset(w, 0, sizeof(w));
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> l >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        if (w[i] != 0)
        {
            e[u[i]].push_back({v[i], w[i]});
            e[v[i]].push_back({u[i], w[i]});
        }
    }
    ijk();
    if (d[t] < l)
        return cout << "NO", 0;
    for (int i =1; i <= m; i++)
        if (w[i] == 0)
        {
            e[u[i]].push_back({v[i], 1});
            e[v[i]].push_back({u[i], 1});
            w[i] = 1;
            ijk();
            if (d[t] < l)
                {
                    w[i] = l - d[t] + 1;
                    e[u[i]].erase(e[u[i]].end());
                    e[v[i]].erase(e[v[i]].end());
                    e[u[i]].push_back({v[i], w[i]});
                    e[v[i]].push_back({u[i], w[i]});
                }
        }
    ijk();
    if (d[t] > l)
        return cout << "NO", 0;
    cout << "YES" << endl;
    for (int i = 1; i <= m; i++)
        cout << u[i] << " " << v[i] << " " << w[i] << endl;
    return 0;
}
