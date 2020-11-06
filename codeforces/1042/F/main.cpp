#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e6+100;

int n, k;
vector <int> e[maxn];
int ans = 1;

int dfs(int u, int par)
{
    if (e[u].size() == 1)
    {
        return 0;
    }
    vector <int> vd;
    for (int v : e[u])
    {
        if (v == par)
        {
            continue;
        }
        int d = dfs(v, u) + 1;
        vd.push_back(d);
    }
    sort(vd.begin(), vd.end());
    while (vd.size() >= 2)
    {
        int d1 = vd.back();
        int d2 = vd[vd.size() -2];
        if (d1 + d2 <= k)
        {
            break;
        }
        ans ++;
        vd.pop_back();
    }
    return vd.back();
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (e[i].size() >= 2)
        {
            dfs(i, 0);
            break;
        }
    }
    cout << ans;
    return 0;
}
