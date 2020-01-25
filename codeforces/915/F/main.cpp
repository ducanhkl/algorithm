#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v;
    int val;
};

const int maxn = 1e6+7;

int n;
int a[maxn], root[maxn], cnt[maxn];

edge e[maxn];

long long ans = 0;

bool cmp(edge x, edge y)
{
    return x.val < y.val;
}

int getroot(int u)
{
    if (root[u] == 0)
        return u;
    return root[u] = getroot(root[u]);
}

void solve()
{
    for (int i = 1; i < n; i++)
        e[i].val = max(a[e[i].u], a[e[i].v]);
    sort(e+1, e+n, cmp);
    edge eg;
    for (int i = 1; i < n; i++)
    {
        eg = e[i];
        int u = getroot(eg.u), v = getroot(eg.v);
        ans = ans + (long long)cnt[u]*cnt[v]*eg.val;
        cnt[v] += cnt[u];
        root[u] = v;
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[i] = {v, u, 0};
    }
    for (int i = 1; i <= n; i++)
        cnt[i] = 1;
    solve();
    memset(root, 0, sizeof(root));
    for (int i = 1; i <= n; i++)
        cnt[i] = 1, a[i] = - a[i];
    solve();
    cout << ans;
    return 0;
}
