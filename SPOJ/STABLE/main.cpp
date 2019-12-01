#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4+100, maxc = 1e8+100;

typedef  pair <int, int> ii;

int d[maxn], cnt[maxn];
int n, m, s ;
vector <int> e[maxn];
map <int, int> cn[maxn];

void ijk()
{
    priority_queue <ii> q;
    for (int i = 1; i <= n; i++)
        d[i] = maxc, cnt[i] = 0;
    d[s] = 0, cnt[s] = 1;
    q.push({0, s});
    while (q.size())
    {
        ii tp = q.top();
        int u = tp.second;
        int w = -tp.first;
        q.pop();
        if (d[u] < w)
            continue;
        for (auto v : e[u])
        {
            int l = w+1;
            if (d[v] < l)
                continue;
            if (d[v] == l)
            {
                cnt[v] += cnt[u];
                cnt[v] = min(cnt[v], maxc);
                continue;
            }
            if (d[v] > l)
            {
                d[v] = l;
                cnt[v] = cnt[u];
                q.push({-d[v], v});
            }
        }
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (cn[u][v])
            continue;
        cn[u][v] = 1;
        e[u].push_back(v);
    }
    ijk();
    int ans = 0;
    /* for (int i = 1; i <= n; i++)
        cout << cnt[i] << " ";
    cout << endl;*/
    for (int i = 1; i <= n; i++)
        if (cnt[i] > 1)
        {
            ans++;
        }
    cout << ans;
    return 0;
}