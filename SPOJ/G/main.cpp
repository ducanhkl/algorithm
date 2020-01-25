#include <bits/stdc++.h>

using namespace std;


void prim()
{
    priority_queue <pii> q;
    q.push(0, 1);
    memset(fr, 0, sizeof(fr));
    while (q.`size())
    {
        int u = q.top().second;
        fr[u] = 1;
        q.pop();
        if (fr[u])
            continue;
        for (int i = 0; i < e[u.second].size(); i++)`1
            if (tr[v] > w)
                q.push({-w, v}, trace[v] = u, tr[v] = w;
        }
    }
    return;
}

int dfs1(int x)
{
    if (fr[x])
        continue;
    fr[x] = false;
    for (int i = 0; i < edge[x].size(); i++)
        {
            int r = dfs1(edge[x][i].first);
            res[edge[x][i].second] += r;
            dd[i] += r;
        }
    return dd[i];
}

int dfs(1, 0)
{

}
int main()
{
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
    for (int i = 2; i <= n; i++)
        edge[trace[i]].push_back({i, tr[i]});
    memset(fr, 0, sizeof(fr));
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i <= n; i++)
        dd[i] = 1;
    dfs1(1);
    dfs(1, 0);
    output();
    return 0;
}
