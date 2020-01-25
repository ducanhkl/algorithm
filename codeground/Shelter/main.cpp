#include <bits/stdc++.h>

#define maxn 1000006

using namespace std;

long long d[maxn], root[maxn];
unsigned long long res1, res2;
vector <pair<int, long long> > e[maxn];
int n, m, k, t;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    int c = 0;
    while (t --)
    {
        res1 = res2 = 0;
        for (int i = 0; i < maxn; i++)
            e[i].resize(0);
        cin >> n >> m >> k;
        for (int i = 0; i < maxn; i++)
            d[i] = LONG_LONG_MAX;
        priority_queue <pair <long long, int> > q;
        for (int i = 1; i <= m; i++)
        {
            long long u, v, w;
            cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        for (int i = 1; i<= k; i++)
        {
            int u;
            cin >> u;
            q.push({0, u});
            d[u] = 0;
            root[u] = u;
        }
        while (q.size())
        {
            int u = q.top().second;
            long long l = -q.top().first;
            q.pop();
            if (d[u] < l)
                continue;
            for (int i = 0; i < e[u].size(); i++)
            {
                int v = e[u][i].first;
                long long w = e[u][i].second;
                if (w+l == d[v])
                    root[v] = min(root[u], root[v]);
                if (w + l < d[v])
                {
                    d[v] = w+l;
                    root[v] = root[u];
                    q.push({-d[v], v});
                }
            }
        }
        for (int i = 1; i <= n; i++)
            res1 += d[i], res2 += root[i];
        cout << "Case #" << ++c << endl;
        cout << res1 << endl << res2 << endl;
    }
    return 0;
}
