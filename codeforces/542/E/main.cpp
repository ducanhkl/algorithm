#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+100;

typedef pair <int, int> ii;

int n, m;
int d[maxn], ufr[maxn], maxlen = 1;
vector <int> e[maxn];
int ans = 0;

int bfs(int x)
{
    memset(ufr, 0, sizeof(ufr));
    deque <ii> q;
    q.push_back({x, 0});
    ufr[x] = 1;
    d[x] = 0;
    while (q.size())
    {
        auto [u, len] = q.front();
        q.pop_front();
        d[x] = max(d[x], len);
        for (auto v : e[u])
        {
            if (ufr[v])
                continue;
            ufr[v] = 1;
            q.push_back({v, len+1});
        }
    }
    return 0;
}


int dfs(int u)
{
    maxlen = max(maxlen, d[u]);
    for (auto v : e[u])
    {
        if (!ufr[v])
        {
            ufr[v] = 3-ufr[u];
            dfs(v);
        } else
        {
            if (ufr[v] == ufr[u])
            {
                cout << -1;
                exit(0);
            }
        }
    }
    return 0;
}

int main()
{
    //freopen("inp.ttx", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >>u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
            bfs(i);
    memset(ufr, 0, sizeof(ufr));
    for (int i = 1; i <= n; i++)
    {
        if (ufr[i])
            continue;
        maxlen = 0;
        ufr[i] = 1;
        dfs(i);
        ans += maxlen;
    }
    cout << ans;
    return 0;
}
