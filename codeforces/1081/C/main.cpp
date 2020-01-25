#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const int maxn = 3e3+100;
int n, m, k;
long long dp[maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    dp[1][0] = m;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
            dp[i][j] = dp[i-1][j];
        for (int j = 1; j <= k; j++)
            dp[i][j] = (dp[i][j] + (m-1)*dp[i-1][j-1]%mod)%mod;
    }
    cout << dp[n][k];
    return 0;
}
