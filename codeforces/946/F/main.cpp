#include <bits/stdc++.h>

using namespace std;

const long long maxn = 110, mod = 1e9+7;
long long dp[maxn][maxn][maxn], g[maxn];
char s[maxn];
int n, x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    g[0] = g[1] = 2;
    for (int i = 2; i <= x; i++)
        g[i] = (g[i-1]*g[i-2])%mod;
    for (int i = 1; i <= n; i++)
        dp[s[i]-'0'][i][i] = 1;
    for (int i = 2; i <= x; i++)
    {
        for (int l = 1; l <= n; l++)
            for (int r = l; r <= n; r++)
            {
                for (int m = l; m < r; m++)
                    dp[i][l][r] = (dp[i][l][r]+dp[i-1][l][m]*dp[i-2][m+1][r]%mod)%mod;
                if (r == n)
                    dp[i][l][r] += dp[i-1][l][r]*g[i-2];
                else
                    dp[i][l][r] += dp[i-1][l][r];
                dp[i][l][r]%=mod;
                if (l == 1)
                    dp[i][l][r] += dp[i-2][l][r]*g[i-1];
                else
                    dp[i][l][r] += dp[i-2][l][r];
                dp[i][l][r] %= mod;
            }
    }
    cout << dp[x][1][n];
    return 0;
}
