#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, m;
long long dd[maxn], ans = 0, a[maxn];
vector <pair<int, int> > e[maxn];

long long ijk(int x, int y)
{
    memset(dd, 60, sizeof(dd));
    dd[x] = 0;
    priority_queue <pair<int, int> > q;
    q.push({0, x});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (q.top().first > dd[u])
            continue;
        if (u == y)
            return dd[u];
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].first;
            int w = e[u][i].second;
            if (dd[v] > dd[u] + w)
            {
                dd[v] = dd[u] + w;
                q.push({-dd[v],v});
            }
        }
    }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
    {
        int x;
        cin >> x;
        if (i != j)
            e[i].push_back({j, x});
    }
    for (int i = 1; i < m; i++)
        ans += ijk(a[i], a[i+1]);
    if (a[1] != 1)
        ans += ijk(1, a[1]);
    if (a[m] != n)
        ans += ijk(a[m], n);
    cout << ans;
    return 0;
}
