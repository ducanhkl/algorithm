#include <bits/stdc++.h>
#define maxn 400

using namespace std;

int n;
int a[maxn], dp[maxn][maxn];
int ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int k = 1; k <= n; k++)
        {
            memset(dp, 0, sizeof(dp));
            for (int i = 1; i <= k; i++)
                for (int j = 1; j <= n-k; j++)
            {
               s dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if (a[i] < a[j+k])
                    dp[i][j] = dp[i-1][j-1]+1;
            }
            ans = max(ans, dp[k][n-k]);
        }
    cout << ans;
    return 0;
}
