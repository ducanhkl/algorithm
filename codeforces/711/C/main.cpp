#include <bits/stdc++.h>
#define maxn 200005

using namespace std;

int n, k;
long long counter[maxn], dp[maxn][10], ufr[maxn];
long long ans = 0;
vector <int> e[maxn];

int dfs(int u, int d)
{
    counter[u] = dp[u][d%k] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (ufr[v])
            continue;
        ufr[v] = 1;
        dfs(v, d+1);
        for (int j = 0; j < k; j++)
            for (int h = 0; h < k; h++)
        {
            int dmodk = (((j+h) - 2*d)%k + k)%k;
            int res = ((k-dmodk)%k+k)%k;
            ans += 1LL*res*dp[u][j]*dp[v][h];
        }
        for (int j = 0; j < k; j++)
            dp[u][j] += dp[v][j];
        counter[u] += counter[v];
    }
    ans += counter[u]*(n-counter[u]);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(counter, 0, sizeof(counter));
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(ufr, 0, sizeof(ufr));
    ufr[1] = 1;
    dfs(1, 0);
    cout << ans/k;
    return 0;
}
