#include <bits/stdc++.h>


using namespace std;


const int maxn = 2*(1e5);
int n;
int d[maxn], m[maxn];
vector <int> e[maxn];
int ans = 0;

void dfs(int u, int par, int h)
{
    d[u] = h+1;
    for (int i = 0; i < (int)e[u].size(); i++)
    {
        int v = e[u][i];
        if (v != par)
            dfs(v, u, h+1);
    }
    if (d[u] < 2)
        return;
    if (e[u].size() == 1)
    {
        m[u] = 3;
        return;
    }
    int cnt[4];
    for (int i = 0; i < 4; i++) cnt[i] = 0;
    for (int i = 0; i < (int)e[u].size(); i++)
    {
        int v = e[u][i];
        if (v != par)
            cnt[m[v]] ++;
    }
    if (cnt[3] == 0 && cnt[2] == 0)
    {
        m[u] = 2;
        return;
    }
    if (cnt[3] == 0 && cnt[2] != 0 && cnt[1] == 0)
    {
        m[u] = 3;
        return;
    }
    if (cnt[3] == 0 && cnt[2] != 0 && cnt[1] != 0)
    {
        m[u] = 2;
        return;
    }
    ans++;
    m[u] = 1;
    for (int i = 0; i < (int)e[u].size(); i++)
        m[e[u][i]] = 2;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(d, 0, sizeof(d));
    memset(m, 0, sizeof(m));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0, -1);
    cout << ans;
    return 0;
}
