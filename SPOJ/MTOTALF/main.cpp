#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;

int d[maxn], f[maxn][maxn], c[maxn][maxn], mark[maxn];
int s, t,cnt = 0;
int n;
vector <int> e[maxn];

int bfs(int S, int T)
{
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == T)
        {
            return true;
        }
        for (auto v : e[u])
        {
            if (!d[v] && f[u][v] < c[u][v])
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}

int visit(int u, int cost)
{
    if (u == t)
    {
        return cost;
    }
    if (mark[u] != cnt)
    {
        mark[u] = cnt;
    }else
    {
        return 0;
    }
    for (auto v: e[u])
    {
        if (f[u][v] < c[u][v])
        {
            if (mark[v] != cnt && d[v] == d[u]+1)
            {
                int x = visit(v, min(cost, c[u][v] - f[u][v]));
                if (x == 0)
                    continue;
                f[u][v] += x;
                f[v][u] -= x;
                return x;
            }
        }
    }
    return 0;
}

int main()
{
    // freopen("inp.txt", "r", stdin);
    int ans = 0;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int w;
        char u, v;
        cin >> u >> v >> w;
        v -= 'A';
        v ++;
        u -= 'A';
        u ++;
        e[u].push_back(v);
        e[v].push_back(u);
        c[u][v] += w;
        c[v][u] += w;
    }
    s = 1;
    t = 'Z'-'A'+1;
    while (bfs(s, t))
    {
        int x;
        do {
            cnt ++;
            x = visit(s, INT_MAX);
            ans += x;
        } while (x != 0);
        // cout << ans << endl;
    }
    cout <<  ans;
    return 0;
}
