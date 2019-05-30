#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
typedef pair <int, long long> pii;
int n, res = 0;
int a[maxn];
vector <pii> e[maxn];

void dfs(int u, int par, int val)
{
    if (val > a[u])
        return;
    res++;
    for (int i = 0; i < e[u].size(); i ++)
    {
        int v = e[u][i].first;
        long long l = e[u][i].second;
        if (v == par)
            continue;
        dfs(v, u, max(val+l, 0LL));
    }
    return (void)0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        long long val;
        int u;
        cin >> u >> val;
        e[u].push_back({i, val});
        e[i].push_back({u, val});
    }
    dfs(1, 0, 0);
    cout << n-res;
    return 0;
}
