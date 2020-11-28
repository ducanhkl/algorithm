#include <bits/stdc++.h>

using namespace std;


const int maxn = 5e3+100;

int dp[maxn][maxn];
int n, m;
char a[maxn], b[maxn];

int main()
{
    int ans = 0;
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1]+2;
            } else
            {
                dp[i][j] = max(max(dp[i-1][j], dp[i][j-1])-1, dp[i][j]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}
