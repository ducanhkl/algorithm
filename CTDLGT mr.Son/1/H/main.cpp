#include <bits/stdc++.h>

using namespace std;

long long dp[13][30][200];
int n, k, s;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    while (cin >> n >> k >> s)
    {
        if (n == 0 && k == 0 && s == 0)
            exit(0);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++)
            dp[0][i][0] = 1;
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 0; k <= s; k++)
        {
            if (j > 0)
                dp[i][j][k] = dp[i][j-1][k];
            if (k >= j)
                dp[i][j][k] += dp[i-1][j-1][k-j];
        }
        cout << dp[k][n][s] << endl;
    }
    return 0;
}
