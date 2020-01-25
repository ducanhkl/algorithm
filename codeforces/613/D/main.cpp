#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;
int n, k;
int ver[maxn], t[maxn], dp[maxn], tin[maxn], cnt = 0, tout[maxn], h[maxn], p[maxn][30],important[maxn], ans = 0;
vector <int> e[maxn];

void dfs(int u, int par = 0)
{
    cnt++;
    tin[u] = cnt;
    h[u] = h[par]+1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        p[v][0] = u;
        for (int j = 1; j < 22; j++)
            p[v][j] = p[p[v][j-1]][j-1];
        dfs(v, u);
    }
    tout[u] = cnt;
    return ;
}

int get(int u, int len)
{
    for (int i = 22; i >= 0; i--)
        if (len & (1<<i))
            u = p[u][i];
    return u;
}

int lca(int u, int v)
{
    if (h[u] > h[v])
        swap(u, v);
    int len = h[v] - h[u];
    v = get(v, len);
    if (u == v)
        return u;
    for (int i = 22; i >= 0; i--)
        if (p[u][i] != p[v][i])
    {
        u = p[u][i];
        v = p[v][i];
    }
    return p[u][0];
}

bool cmp(int u, int v)
{
    return tin[u] < tin[v];
}

bool compare(int u, int v)
{
    return tin[u] < tin[v] && tout[u] >= tout[v];
}

bool buildGraph()
{
    for (int i = 1; i < k; i++)
        ver[i+k] = lca(ver[i], ver[i+1]);
    sort(ver+1, ver+2*k, cmp);
    int cnter = unique(ver+1, ver+2*k)-ver-1;
    for (int i = 1; i <= cnter; i++)
        e[ver[i]].clear();
    stack <int> s;
    s.push(ver[1]);
    for (int i = 2; i <= cnter; i++)
    {
        int v = ver[i];
        while (!compare(s.top(), v))
               s.pop();
        int u = s.top();
        if (important[u] && important[v] && u == p[v][0])
            return 0;
        s.push(v);
        e[u].push_back(v);
    }
    return 1;
}

void dfsSolve(int u)
{
    int cnter = 0;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        dfsSolve(v);
        cnter += dp[v];
    }
    if (important[u])
    {
        ans += cnter;
        dp[u] = 1;
    } else
    {
        if (cnter >= 2)
            ans++, dp[u] = 0;
        else if (cnter == 1)
            dp[u] = 1;
        else
            dp[u] = 0;
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(h, 0, sizeof(h));
    memset(tin, 0, sizeof(tin));
    memset(tout, 0, sizeof(tout));
    memset(dp, 0, sizeof(dp));
    memset(p, 0, sizeof(p));
    memset(important, 0, sizeof(important));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
    dfs(1);
    int q;
    cin >> q;
    while (q--)
    {
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> ver[i];
            important[ver[i]] = 1;
            t[i] = ver[i];
        }
        sort(ver+1, ver+k+1, cmp);
        if (!buildGraph())
        {
            cout << -1 << endl;
        } else
        {
            ans = 0;
            dfsSolve(ver[1]);
            cout << ans << endl;
        }
        for (int i = 1; i <= k; i++)
            important[t[i]] = 0;
    }
    return 0;
}
