#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353 ;
const int maxn = 1e3+10;
long long dp[maxn][maxn][5];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= 4; i++)
        dp[1][1][i] = 1;
    for (int i = 2; i <= m; i++)
    {
        dp[1][i][1] = (dp[1][i-1][1] + dp[1][i-1][4])%mod;
        dp[1][i][2] = (dp[1][i-1][3] + dp[1][i-1][2])%mod;
        dp[1][i][3] = (dp[1][i-1][2] + dp[1][i-1][3])%mod;
        dp[1][i][4] = (dp[1][i-1][4] + dp[1][i-1][1])%mod;
    }
    for (int i = 2; i <= n; i++)
    {
        dp[i][1][1] = (dp[i-1][1][1] + dp[i-1][1][2])%mod;
        dp[i][1][2] = (dp[i-1][1][1] + dp[i-1][1][2])%mod;
        dp[i][1][3] = (dp[i-1][1][3] + dp[i-1][1][4])%mod;
        dp[i][1][4] = (dp[i-1][1][4] + dp[i-1][1][3])%mod;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            for (int k = 1; k <= 4; k++)
                for (int h = 1; h <= 4; h++)
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-1][h])%mod;
    cout << (dp[n][m][1]+dp[n][m][2]+dp[n][m][3]+dp[n][m][4])%mod;
    return 0;
}
