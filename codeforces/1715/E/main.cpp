#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
const long long maxc = 1e16+1;

vector<pair<int, long long>> e[maxn];
int n, m, k;
long long dis[maxn], new_dis[maxn];
int vis[maxn];

void ijk()
{
    priority_queue<pair<long long,int>>pq;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i ++)
    {
        pq.push({ -dis[i], i});
    }
    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        d = -d;
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (auto [v, w] : e[u])
        {
            long long new_d = w + d;
            if (new_d < dis[v])
            {
                dis[v] = new_d;
                pq.push({-new_d, v});
            }
        }
    }
}

void calc(int l, int r, int u, int v)
{
    if (l > r)
    {
        return;
    }

    long long mid = (l+r)/2;

    int opt_p = u;
    long long opt_v = dis[u] + (long long)(u-mid)*(u-mid);
    for (long long i = u + 1; i <= v; i++ )
    {
        long long val = dis[i] + (i-mid)*(i-mid);
        if (val < opt_v)
        {
            opt_p = i;
            opt_v = val;
        }
    }
    new_dis[mid] = opt_v;
    calc(l, mid-1,  u, opt_p);
    calc(mid+1, r, opt_p, v);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = maxc;
    }
    dis[1] = 0;

    ijk();

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            new_dis[j] = maxc;
        }
        calc(1, n, 1, n);
        for (int j = 1; j <= n; j++)
        {
            dis[j] = new_dis[j];
        }
        ijk();
    }

    for (int i = 1; i <= n; i++)
    {
        cout <<dis[i] << " ";
    }

    return 0;
}
