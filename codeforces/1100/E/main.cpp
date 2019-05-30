#include <bits/stdc++.h>
#define maxn 100010

using namespace std;


struct data
{
    int u, v, w;
} g[maxn];

vector <int> e[maxn], res;
long long l, r, mid;
int n, m, id[maxn], cnt, ans = 0, dd[maxn];

void reset()
{
    memset(dd, 0, sizeof(dd));
    memset(id, 0, sizeof(id));
    cnt = 0;
}

int check(long long x)
{
    stack <int> s;
    reset();
    for (int i = 1; i <= m; i++)
        if (g[i].w > x)
            dd[g[i].v]++;
    for (int i = 1; i <= n; i++)
        if (dd[i] == 0)
            s.push(i);
    while (s.size())
    {
        int u = s.top();
        s.pop();
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = g[e[u][i]].v;
            int w = g[e[u][i]].w;
            if (w > x && --dd[v] == 0)
                s.push(v);
        }
        id[u] = ++cnt;
    }
    return cnt == n;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back(i);
        g[i] = {u, v, w};
    }
    l = 0, r = 1e9+10;
    while (l <= r)
    {
        mid = (l+r)/2;
        if (check(mid))
            ans = mid, r = mid-1;
        else
            l = mid+1;
    }
    reset();
    check(ans);
    for (int i = 1; i <= m; i++)
        if (id[g[i].u] > id[g[i].v])
            res.push_back(i);
    cout << ans << " " << res.size() << endl;
    for (int i = 0; i < (int)(res.size()); i++)
        cout << res[i] << " ";
    return 0;
}
