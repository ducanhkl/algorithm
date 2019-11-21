#include <bits/stdc++.h>

using namespace std;

const int maxn = 2020, maxbit  = 1<<12;

int n, m;

int dp[maxbit], vis[maxbit], par[maxbit];
vector <int> f[maxn];
int a[20][maxn];

// int par luu trang thai co ban cua p;
// dp ket qua
// luu f cac trang thai co bit thu i duoc bat

void init()
{
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    // tim p
    for (int t = 0; t < (1<<n); t++)
    {
        if (vis[t])
            continue;
        int nt = t;
        par[t] = t;
        for (int i = 1; i < n; i++)
        {
            nt <<= 1;
            if ((nt >> n) & 1)
            {
                nt ^= (1 << n);
                nt ^= 1;
            }
            if (nt != t)
            {

                par[nt] = t;
                vis[nt] = 1;
            }
        }
    }
    // tim f
    for (int t = 0; t < (1<<n); t++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((t >> i) & 1)
                f[i].push_back(t);
        }
    }
}


void solve()
{
    int ans = 0;
    for (int j = 1; j <= m; j++)
    {
        for (int i = 0; i < n;  i++)
        {
            for (auto v : f[i])
            {
                dp[v] = max(dp[v], dp[(v^(1<<i))] + a[i][j]);
            }
        }
        for (int i = 0; i < (1<<n); i++)

            dp[par[i]] = max(dp[par[i]], dp[i]);
        for (int i = 0; i < (1<<n); i++)
        {
            dp[i] = dp[par[i]];
            ans = max(ans, dp[i]);
        }
    }
    for (int i = 0; i <= n; i++)
        f[i].resize(0);
    cout << ans << endl;
}

int main() {
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--)
    {
        cin >>  n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        }
        init();
        solve();
    }
    return 0;
}