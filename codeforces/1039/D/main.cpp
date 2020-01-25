#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

int n;
int dp[maxn], ans[maxn];
vector <int> e[maxn];

int dfs(int u, int par, int k)
{
    int res = 0, mx1 = 0, mx2 = 0;
    dp[u] = 0;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        res += dfs(v, u, k);
        mx2 = max(mx2, dp[v]);
        if (mx2 > mx1)
            swap(mx2, mx1);
    }
    if (mx1+mx2+1 >= k)
        res++, dp[u] = 0;
    else
        dp[u] = mx1+1;
    return res;
}

void solve(int u, int v, int l, int r)
{
    if (u > v || l > r)
        return ;
    if (l == r)
    {
        for (int i = u; i <= v; i++)
            ans[i] = l;
        return ;
    }
    int mid = (u+v)>>1;
    int res = dfs(1, 0, mid);
    ans[mid] = res;
    solve(u, mid-1, res, r);
    solve(mid+1, v, l, res);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int fast = dfs(1, n, min(n, 1500));
    solve(1, min(n,1500), 0, n);
    if (n > 1500)
        solve(1501, n, 0, fast);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
