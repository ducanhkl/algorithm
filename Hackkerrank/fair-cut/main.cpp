#include <bits/stdc++.h>
#define maxn 200
#define maxc 2010
using namespace std;

int n, r, s, a[maxn];
long long dp[maxn][maxn][maxc+100], ans = 0;
const long long mod = 1e9+7;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> r >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
        dp[i][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            {
                for (int k=0; k < a[i]; k++)
                    dp[i][j][k] = dp[i-1][j][k];
                for (int k = a[i]; k <= maxc; k++)
                    dp[i][j][k] = (dp[i-1][j][k] + dp[i-1][j-1][k-a[i]])%mod;
            }
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[n][i][(s+r)/2]*dp[n][i][(r-s)/2])%mod;
    cout << ans;
    return 0;
}
