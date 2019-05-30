#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3+100;
int n, k, ans = 1;
int dp[maxn][maxn], a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    dp[1][1] = 1;
    int l = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            dp[i][j] = dp[i-1][j];
        while (a[i] - a[l] > 5)
            l++;
        for (int j = 0; j <= k; j++)
            {
                dp[i][j+1] = max(dp[i][j+1], dp[l-1][j] + i-l+1);
                ans = max(ans, dp[i][j]);
            }
    }
    cout << ans;
    return 0;
}
