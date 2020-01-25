#include <bits/stdc++.h>
#define maxn 100006
#define pii pair <int, long long>

using namespace std;

stack <int> t1, t2;
int n, m, d1[maxn], d2[maxn], dd[maxn];
vector <pii> e[maxn];
pii trace[maxn], res[maxn];

int bfs(int x, int *d)
{
    queue <int> q;
    q.push(x);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].first;
            if (d[u] + 1 < d[v])
            {
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++)
        d1[i] = d2[i] = INT_MAX;
    d1[1] = 0, d2[n] = 0;
    bfs(1, d1);
    bfs(n, d2);
    t1.push(1);
    while (true)
    {
        while (t1.size())
        {
            memset(res, 0, sizeof(res));
            int u = t1.top(), sl = 0, mii = INT_MAX;
            t1.pop();
            dd[u] = 1;
            for (int i = 0; i < e[u].size(); i++)
            {
                int v = e[u][i].first;
                int w = e[u][i].second;
                if (d1[v] + d2[v] == d1[n] && dd[v] == 0 && d1[u] + 1 <= d1[v])
                {
                    mii = min(w, mii);
                    res[++sl] = e[u][i];
                }
            }
            for (int i = 1; i <= sl;i++)
                if (res[i].second == mii)
                    {
                        t2.push(res[i].first);
                        trace[res[i].first].first = u;
                        trace[res[i].first].second = mii;
                    }
        }
        while (t2.size())
        {
            t1.push(t2.top());
            t2.pop();
        }
        if (t1.size() == 0 && t2.size() == 0)
            break;
    }
    int i = n, __d = 0, ans[maxn];
    cout << d1[n] << endl;
    while (i != 1)
    {
        ans[++__d] = trace[i].second;
        i = trace[i].first;
    }
    for (int i = __d; i >= 1; i--)
        cout << ans[i] << " ";
    return 0;
}
