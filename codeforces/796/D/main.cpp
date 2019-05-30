#include <bits/stdc++.h>
#define maxn 300005

using namespace std;

int vis[maxn], n, k, w, edge[maxn];
set <int> ans;
vector <pair<int, int>> e[maxn];
queue <int> q;

int ijk()
{
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].first;
            int w = e[u][i].second;
            if (!vis[v])
            {
                ans.erase(w);
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(vis, 0, sizeof vis);
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> w;
    for (int i = 1; i <= k; i++)
    {
        int u;
        cin >> u;
        q.push(u);
        vis[u] = 1;
    }
    for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back({v, i});
            e[v].push_back({u, i});
            ans.insert(i);
        }
    ijk();
    cout << ans.size() << endl;
    for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << *it << " ";
    return 0;
}
