#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, m;
vector <pair<int, long long> > e[maxn];
int dd[maxn], cnt[maxn], root[maxn];
long long ans = LONG_LONG_MAX, res, a[maxn], k;
vector <long long> vt;

void dfs(int u)
{
    dd[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].first;
        if (dd[v] == 0)
            root[v] = u, dfs(v);
    }
    cnt[u] += a[u];
    for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].first;
            if (root[u] == v)
                continue;
            long long w = e[u][i].second;
            cnt[u] += cnt[v];
            vt.push_back(cnt[v]*w);
        }
}
void init()
{
    vt.resize(0);
    memset(root, 0, sizeof(root));
    memset(dd, 0, sizeof(dd));
    memset(cnt, 0, sizeof(cnt));
    res = 0;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        memset(e, 0, sizeof(e));
        ans = LONG_LONG_MAX;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i < n; i++)
        {
            long long u, v, w;
            scanf("%lld%lld%lld", &u, &v, &w);
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        for (int i = 1; i <= n; i++)
        {
            init();
            dfs(i);
            sort(vt.begin(), vt.end(), greater<long long>());
            for (int i = k; i < vt.size(); i++)
                res += vt[i];
            ans = min(res, ans);
        }
        //cout << vt.size() << endl;
        cout << ans << endl;
    }
    return 0;
}
