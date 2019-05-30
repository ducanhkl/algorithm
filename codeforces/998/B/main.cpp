#include <bits/stdc++.h>

using namespace std;

int n, c;
int a[200], b[200];
int dp[200][200];
int sl[200], sc[200];
int ans = 0;

int main()
{
    for (int i = 0; i < 200; i++)
        sl[i] = sc[i] = 0;
    for (int i = 1; i < 200; i++)
        for (int j = 1; j < 200; j++)
            dp[i][j] = 1234567;
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i]%2)
                sl[i] ++;
            else sc[i]++;
            sl[i] += sl[i-1];
            sc[i] += sc[i-1];
        }
    for (int i = 1; i < n; i++)
    {
        int t = abs(a[i+1] - a[i]);
        for (int j = i-1; j >= 0; j --)
            for (int k = 1; k <= j+1; k++)
                if (sl[i] - sl[j] == sc[i] - sc[j] && dp[j][k-1] != 1234567)
            {
                dp[i][k] = min(dp[j][k-1] + t, dp[i][k]);
                //ans = max(ans, dp[i][k]);
            }
    }
    for (int i = n-1; i > 0; i --)
        if (sl[n] - sl[i] == sc[n] - sc[i])
            for (int j = 1; j <= 100; j++)
                if (dp[i][j] <= c)
                    ans = max(ans, j);
    cout << ans;
    return 0;
}
