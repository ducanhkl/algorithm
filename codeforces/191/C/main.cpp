#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int n;
int ans[maxn];
vector < pair<int, int> > e[maxn];
vector < int> g[maxn];

set <int> dfs(int u, int par)
{
    set <int> res;
    res.clear();
    for (int i = 0; i < (int)e[u].size(); i++)
    {
        int v = e[u][i].first;
        int pos = e[u][i].second;
        if (v == par)
            continue;
        set <int> listVer = dfs(v, u);
        ans[pos] = listVer.size();
        if (res.size() < listVer.size())
            swap(res, listVer);
        for (set<int>::iterator it = listVer.begin(); it != listVer.end(); it++)
        {
            int val = *it;
            if (res.count(val))
            {
                res.erase(val);
            } else
            {
                res.insert(val);
            }
        }
    }
    for (int i = 0; i < (int)g[u].size(); i++)
    {
        int v = g[u][i];
        if (res.count(v))
        {
            res.erase(v);
        } else
        {
            res.insert(v);
        }
    }
    // cout << u << " " << res.size() << endl;
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v,  i});
        e[v].push_back({u, i});
    }
    int q;
    cin >> q;
    for (int i =1 ; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(i);
        g[v].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}
