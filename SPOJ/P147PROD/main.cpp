#include <bits/stdc++.h>

using namespace std;

unsigned long long dp[5][2004];
int n;

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int dem = 0;
    n = 1001;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 4; j++)
            dp[j][i] = LONG_LONG_MAX;
    dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
    for (int i = 2;  i <= n; i++)
        dp[i][3] = dp[i-1][3]*2LL+1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            dp[i][4] = min(dp[i][4], dp[j][4] + dp[i-j][3] + dp[j][4]);
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        cout << "Case " << ++dem << ": " << dp[n][4] << endl;
    }
	return 0;
}
