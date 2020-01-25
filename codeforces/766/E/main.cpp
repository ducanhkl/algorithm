#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

int n;
long long a[maxn], f[maxn][2], ufr[maxn];
long long ans = 0;
vector <int> e[maxn];

void dfs (int u, int k)
{
    ufr[u] = 1;
    int t = ((a[u]>>k)%2);
    f[u][t] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (ufr[v])
            continue;
        dfs(v, k);
        ans += (1LL<<k)*(f[u][1]*f[v][0]+f[u][0]*f[v][1]);
        f[u][1] += f[v][t^1];
        f[u][0] += f[v][t^0];
    }
    return (void)0;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], ans += a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < 21; i++)
    {
        memset(ufr, 0, sizeof(ufr));
        memset(f, 0, sizeof(f));
        dfs(1, i);
    }
    cout << ans;
    return 0;
}
