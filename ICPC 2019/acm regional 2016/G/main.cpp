#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, int> ii;

// ans = caykhung + l* (n-s);

const int maxn = 1e4+100;

int n, m;
long long l, s;
vector <ii> e[maxn];
int dd[maxn], a[maxn];

void init()
{
    for (int i = 1; i <= n; i++)
        e[i].clear();
    for (int i = 0; i <= n; i++)
        dd[i] = 0;
}

void solve()
{
    long long ans = l*(n-s);
    priority_queue <ii> q;
    for (int i = 1; i <= s; i++)
    {
        dd[a[i]] = 1;
        for (auto eg : e[a[i]])
        {
            q.push({-eg.second, eg.first});
        }
    }
    while (q.size())
    {
        int u = q.top().second;
        long long w = -q.top().first;
        q.pop();
        if (dd[u])
            continue;
        dd[u] = 1;
        ans += w;
        for (auto eg : e[u])
        {
            int v = eg.first;
            int l = eg.second;
            if (dd[v])
                continue;
            q.push({-l ,v});
        }
    }
    cout << ans << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        init();
        cin >> n >> m >> l >> s;
        for (int i = 1; i <= s; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            long long u, v, w;
            cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        solve();
    }
    return 0;
}
