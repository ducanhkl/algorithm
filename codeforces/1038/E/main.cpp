#include <bits/stdc++.h>
#define maxn 1006

using namespace std;

int n;
long long dp[maxn][maxn][5][5], ans = 0;


int main()
{
    freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            for (int u = 0; u <=4; u++)
                for (int v = 0; v <= 4; v++)
                    dp[i][j][u][v] = -1e9;
    for (int i = 1; i <= n; i++)
    {
        int c1, v, c2;
        cin >> c1 >> v >> c2;
        dp[i][i][c1][c2] = dp[i][i][c2][c1] = v;
    }
    for (int i = n; i >= 1; i--)
        for (int j = i; j <= n; j++)
            for (int u = 1; u <= 4; u++)
                for (int v = 1; v <= 4; v++)
                    {
                        for (int k = i; k < j; k++)
                        {
                            dp[i][j][u][v] = max(dp[i][j][u][v], max(dp[i][k][u][v], dp[k+1][j][u][v]));
                            for (int p = 1; p <= 4; p++)
                                dp[i][j][u][v] = max(dp[i][j][u][v], max(dp[i][k][u][p] + dp[k+1][j][p][v], dp[i][k][p][v] + dp[k+1][j][u][p]));
                        }
                        ans = max(ans, dp[i][j][u][v]);
                    }
    cout << ans;
    return 0;
}
