#include <bits/stdc++.h>
#define pii pair <long long, int>
#define maxn 1004

using namespace std;

long long dd[maxn];
int n, m;
vector <pii> e[maxn];

void prim()
{
    int dd[maxn];
    for (int i = 0; i < maxn; i++)
        dd[i] = INT_MAX;
    dd[1] = 0;
    priority_queue <pii> q;
    q.push({0, 1});
    while (q.size())
    {
        int u = q.top().second;
        long long w = -q.top().first;
        q.pop();
        if (w > dd[u])
            continue;
        dd[u] = w;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].first;
            long long l = e[u][i].second;
            if (l < dd[v])
                q.push({-e[u][i].second, e[u][i].first});
        }
    }
    cout << *max_element(dd+1, dd+n+1);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    prim();
    return 0;
}
