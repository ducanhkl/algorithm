#include <bits/stdc++.h>

using namespace std;



const int maxn = 200, maxc = 1e9;
int n, q, s;
int dp[maxn][maxn*maxn+100], a[maxn], ans = maxc;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> q >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= maxn*maxn; j++)
            dp[i][j] = maxc;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i-1; j >= 0; j--)
        {
            for (int k = 0; k <= i*j; k++)
                dp[j+1][k+i-j-1] = min(dp[j+1][k+i-j-1], dp[j][k] + a[i]);
        }
    }
    for (int i = 0; i <= min(s, n*n); i++)
    {
        ans = min(ans, dp[q][i]);
    }
    cout << ans;
    return 0;
}
