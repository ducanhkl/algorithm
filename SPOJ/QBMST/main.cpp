#include <bits/stdc++.h>
#define maxn 10001
#define pii pair <int, long long>

using namespace std;

vector <pii> e[maxn];
int n, m;

int prim()
{
    long long res = 0;
    vector <int> free(n+10, 1);
    priority_queue <pii> q;
    q.push({0, 1});
    while (!q.empty())
    {
        pii point = q.top();
        q.pop();
        int u = point.second;
        int l = -point.first;
        if (!free[u])
            continue;
        res += l;
        free[u] = false;
        for (int i = 0; i < e[u].size(); i++)
            if (free[e[u][i].first])
                q.push({-e[u][i].second, e[u][i].first});
    }
    return res;
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
    cout << prim();
    return 0;
}
