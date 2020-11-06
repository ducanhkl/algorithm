#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
const int maxn = 3*1e5+100;

int d1[maxn], dn[maxn], a[maxn];
int n, m, k;
vector <ii> vi;
vector <int> e[maxn];
int ans = 0;

void ijk(int x, int d[maxn])
{
    for (int i = 0; i < maxn; i++)
        d[i] = INT_MAX;
    d[x] = 0;
    priority_queue <ii> q;
    q.push({0, x});
    while (q.size())
    {
        int u = q.top().second;
        int len = -q.top().first;
        q.pop();
        if (len > d[u])
            continue;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i];
            int w = 1;
            if (len+w >= d[v])
                continue;
            d[v] = len+w;
            q.push({-d[v], v});
        }
    }
    return ;
}

bool cmp(ii x, ii y)
{
    return x.second - x.first < y.second - y.first;
}

void input()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
}

void solve()
{
    ijk(1, d1);
    ijk(n, dn);
    for (int i = 1; i <= k; i++)
    {
        vi.push_back({d1[a[i]], dn[a[i]]});
    }
    sort(vi.begin(), vi.end(), cmp);
    int res = vi[0].second;
    for (int i = 1; i < vi.size(); i++)
    {
        ans = max(ans, vi[i].first+res+1);
        res = max(res, vi[i].second);
    }
    cout << min(d1[n], ans);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}
