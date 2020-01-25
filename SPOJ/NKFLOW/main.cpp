#include <bits/stdc++.h>
#define maxn 1004

using namespace std;

int trace[maxn];
int e[maxn][maxn], f[maxn][maxn];
long long ans = 0;
int s, t, n, m;

bool findpath()
{
    queue <int> q;
    memset(trace, 0, sizeof(trace));
    trace[s] = n+1;
    q.push(s);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
            if (trace[i] == 0 && e[u][i] > f[u][i])
                {
                    trace[i] = u;
                    if (i == t)
                        return true;
                    q.push(i);
                }
    }
    return false;
}

void incflow()
{
    int u = t;
    int delta = INT_MAX;
    while (u != s)
    {
        delta = min(delta, e[trace[u]][u]-f[trace[u]][u]);
        u = trace[u];
    }
    u = t;
    while (u != s)
    {
        int v = trace[u];
        f[v][u] += delta;
        f[u][v] -= delta;
        u = v;
    }
}

void output()
{
    for (int i = 1; i <= n; i++)
        if (f[s][i] > 0)
            ans += f[s][i];
    cout << ans;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(e, 0, sizeof(e));
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        e[u][v] = c;
    }
    while (findpath())
        incflow();
    output();
    return 0;
}
