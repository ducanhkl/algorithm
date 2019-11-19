#include <bits/stdc++.h>

using namespace std;


const int maxn = 2e5+100;

typedef pair <int, long long> ii;

int n, m;
vector <ii> e[maxn];
long long d[maxn], a[maxn];


priority_queue < pair <long long, int> > q;

void solve()
{
    while (q.size())
    {
        auto [w, u] = q.top();
        w = -w;
        q.pop();
        if (w > d[u])
            continue;
        for (auto [v, l] : e[u])
        {
            if (w+l < d[v])
            {
                d[v] = l+w;
                q.push({-d[v], v});
            }
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i  = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v  >> w;
        w *= 2;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        d[i] = a[i];
    for (int i = 1; i <= n; i++)
    {
        q.push({-d[i], i});
    }
    solve();
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    return 0;
}
