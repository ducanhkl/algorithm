#include <bits/stdc++.h>

using namespace std;

long long dp[2001][2001][2], a[2001][2001];
int n, m;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        dp[0][0][0] = dp[0][0][1] = 0;
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j][1] = dp[i][j][0] = 1234567898;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
        {
            if (i-1 > 0)
                dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1] + a[i][j]);
            else dp[i][j][0] = dp[i-1][j][1] + a[i][j];
            if (j-1 > 0)
                dp[i][j][1] = min(dp[i][j-1][1], dp[i][j-1][0] + a[i][j]);
            else dp[i][j][1] = dp[i][j-1][0] + a[i][j];
        }
        cout << min(dp[m][n][1], dp[m][n][0]) << endl;
    }
    return 0;
}
