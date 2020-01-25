#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, k;
int par[maxn], dd[maxn], cnt, trace[maxn][30];
vector <int> e[maxn];

int dfs(int u, int p)
{
    par[u] = p;
    trace[u][0] = p;
    for (int i = 1; i <= 22; i++)
        trace[u][i] = trace[trace[u][i-1]][i-1];
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == p)
            continue;
        dfs(v, u);
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(par, 0, sizeof(par));
    memset(trace, 0, sizeof(trace));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(n, n);
    dd[n] = 1, cnt = n-k-1;
    for (int i = n-1; i >= 1; i--)
    {
        if (dd[i])
            continue;
        int len = 1, u = i;
        for (int j = 22; j >= 0; j--)
            if (!dd[trace[u][j]])
                u = trace[u][j], len += 1<<j;
        if (len <= cnt)
        {
            u = i;
            cnt -= len;
            while (!dd[u])
                dd[u] = 1, u = par[u];
        }
    }
    for (int i = 1; i <= n; i++)
        if (!dd[i])
            cout << i << " ";
}
