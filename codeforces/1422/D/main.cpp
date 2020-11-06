#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, long long> pii;

const long long maxn = 1e5+100;

long long n, m, sx, sy, fx,  fy;
long long x[maxn], y[maxn];
long long dis[maxn];
vector <pii> list_x, list_y, e[maxn];

void add(long long u, long long v)
{
    long long d = min(abs(x[u] - x[v]), abs(y[u]-y[v]));
    e[u].push_back({ v, d});
    e[v].push_back({u, d});
}

void bfs()
{
    priority_queue <pii> q;
    for (long long i = 1; i <= m; i++)
    {
        dis[i] = min(abs(x[i] - sx), abs(y[i] - sy));
        q.push({-dis[i], i});
    }
    while (q.size())
    {
        pii t = q.top();
        q.pop();
        long long u = t.second;
        long long l = -t.first;
        if (dis[u] < l)
            continue;
        for (long long i = 0; i < e[u].size();i++)
        {
            long long v = e[u][i].first;
            long long w = e[u][i].second;
            if (dis[v] > l + w)
            {
                dis[v] = l+w;
                q.push({-dis[v], v});
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> sx >> sy >> fx>> fy;
    for (long long i = 1; i <= m; i++)
    {
        cin >> x[i] >> y[i];
        list_x.push_back({x[i], i});
        list_y.push_back({y[i], i});
    }
    sort (list_x.begin(), list_x.end());
    sort (list_y.begin(), list_y.end());
    for (long long i = 0; i < m-1;  i++)
    {
        add(list_x[i].second,list_x[i+1].second);
        add(list_y[i].second,list_y[i+1].second);
    }
    bfs();
    long long ans  = abs(sx-fx) + abs(sy-fy);
    for (long long i = 1; i <= m;  i++)
    {
        ans = min(ans, dis[i] + abs(fx-x[i]) + abs(fy-y[i]));
    }
    cout << ans;
    return 0;
}
