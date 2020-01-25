#include <bits/stdc++.h>

using namespace std;

const int maxn = 600;
const long long mod = 998244353;

long long dp[3][maxn][maxn], sum[maxn], cnt[maxn], ans = 0;
int n, k;


void solve()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        int tt1 = i%2;
        int tt2 = !tt1;
        memset(dp[tt2], 0, sizeof(dp[tt2]));
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
        {
            dp[tt2][j+1][max(k, j+1)] = (dp[tt2][j+1][max(k, (j+1))] + dp[tt1][j][k])%mod;
            dp[tt2][1][max(k, 1)] = (dp[tt2][1][max(k, 1)] + dp[tt1][j][k])%mod;
        }
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            cnt[i] = (cnt[i] + dp[n%2][j][i])%mod;
    for (int i = 1; i <= n; i++)
        sum [i] = (sum[i-1] + cnt[i])%mod;
    for (int i = 1; i <= n; i++)
        ans = (ans+cnt[i]*(sum[min(n, (k-1)/i)])%mod)%mod;
    ans = ans*((mod+1)/2)%mod;
    ans %= mod;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    solve();
    cout << ans;
    return 0;
}
