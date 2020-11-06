#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

typedef pair <int, int> pii;
typedef pair <pii, int> piii;

int n, m;
int par[maxn];
vector <pii> e[maxn];
set <pii> s;
pii d[maxn];
vector <pii> ans;

void ijk (int uu)
{
    priority_queue <piii, vector<piii>, greater<piii>> q;
    q.push({{0, 0}, 1});
    for (int i = 0; i <= n; i++)
        d[i] = {INT_MAX, INT_MAX};
    d[1] = {0, 0};
    while (q.size())
    {
        piii top = q.top();
        q.pop();
        int u = top.second;
        pii l = top.first;
        if (l > d[u])
            continue;
        for (auto edge: e[u])
        {
            int v = edge.first;
            int w = edge.second;
            pii mp = {d[u].first+1, d[u].second+!w};
            if (mp < d[v])
            {
                d[v] = mp;
                par[v] = u;
                q.push({d[v], v});
            }
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1;  i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
        if (w == 1)
        {
            pii edge = {min(u, v), max(u, v)};
            s.insert(edge);
        }
    }
    ijk(n);
    int now = n;
    while (now != 1)
    {
        int u = now;
        int v = par[u];
        pii edge = {min(u, v), max(u, v)};
        if (s.count(edge))
        {
            s.erase(edge);
        }
        else
        {
            ans.push_back(edge);
        }
        now = par[now];

    }
    cout << ans.size() + s.size() << endl;
    for (auto v : ans)
    {
        cout << v.first << " " << v.second  <<  " " << 1 << endl;
    }
    for (auto v : s)
    {
        cout << v.first << " " << v.second << " " << 0 << endl;
    }
    return 0;
}
