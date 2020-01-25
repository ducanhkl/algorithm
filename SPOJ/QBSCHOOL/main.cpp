#include <bits/stdc++.h>
#define maxn 10000

using namespace std;

int n, m;
vector <pair<int, long long> > e[maxn+1];
long long d[maxn+1], s[maxn+1];

void dijkstra()
{
    for (int i = 1; i <= maxn; i++)
        d[i] = LONG_LONG_MAX;
    d[1] = 0;
    memset(s, 0, sizeof(s));
    s[1] = 1;
    priority_queue <pair<long long, int> > q;
    q.push({0LL, 1});
    while(!q.empty())
    {
        pair <long long, int> p = q.top();
        q.pop();
        long long w = -p.first;
        int u = p.second;
        if (w > d[u])
            continue;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].first;
            int l = e[u][i].second+w;
            if (l < d[v])
            {
                d[v] = l;
                s[v] = s[u];
                q.push({-d[v], v});
                continue;
            }
            if (l == d[v])
                s[v] += s[u];
        }
    }
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int k, u, v, w;
        cin >> k >> u >> v >> w;
        e[u].push_back({v, w});
        if (k == 2)
            e[v].push_back({u, w});
    }
    dijkstra();
    cout << d[n] << " " <<  s[n];
    return 0;
}
