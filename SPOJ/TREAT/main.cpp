#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+100;

int n;
int e[maxn], num[maxn], low[maxn], f[maxn], tp[maxn], ufr[maxn], dd[maxn];
int cpncnt = 0, cnt = 0;
stack <int> s;
vector <int> eg[maxn];
map <int, int> mark[maxn];

void dfs1(int u)
{
    num[u] = ++cnt;
    low[u] = num[u];
    s.push(u);
    int v = e[u];
    if (!dd[v])
    {
        if (num[v] != 0)
            low[u] = min(low[u], num[v]);
        else
        {
            dfs1(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u])
    {
        cpncnt ++;
        do
        {
            v = s.top();
            s.pop();
            tp[v] = cpncnt;
            f[cpncnt] ++;
            dd[v] = 1;
        } while (v != u && s.size());
    }
    return ;
}

void dfs2(int u, int par)
{
    if (ufr[u])
        return ;
    ufr[u] = 1;
    for (auto v : eg[u])
    {
        if (v == par)
            return ;
        dfs2(v, u);
        f[u] += f[v];
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    //ios_base::sync_with_stdio(0);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        e[i] = x;
    }
    for (int i = 1; i <= n; i++)
    {
        if (dd[i] == 0)
        {
            dfs1(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int u = tp[i];
        int v = tp[e[i]];
        if (u == v || mark[u][v])
            continue;
        mark[u][v] = 1;
        eg[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        dfs2(i, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", f[tp[i]]);
    }
    return 0;
}
