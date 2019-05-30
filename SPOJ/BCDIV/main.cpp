#include <bits/stdc++.h>

using namespace std;

unsigned long long dp[30][30];
int n, k, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t --)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> k;
        dp[0][0]= 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++)
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j]*j;
        cout << dp[n][k] << endl;
    }
    return 0;
}
