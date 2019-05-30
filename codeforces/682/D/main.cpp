#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;
int n, m, k;
int dp[11][maxn][maxn][2];
char a[maxn], b[maxn];
string s, t;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    cin >> s >> t;
    for (int i = 0; i < n; i++)
        a[i+1] = s[i];
    for (int i = 0; i < m; i++)
        b[i+1] = t[i];
    for (int tt = 1; tt <= k; tt++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
    {
        dp[tt][i][j][0] = max(dp[tt][i-1][j][0], max(dp[tt][i][j-1][0], max(dp[tt][i-1][j][1], dp[tt][i][j-1][1])));
        if (a[i] == b[j])
            dp[tt][i][j][1] = max(dp[tt][i][j][1], max(dp[tt-1][i-1][j-1][0], dp[tt][i-1][j-1][1])+1);
        else
            dp[tt][i][j][1] = 0;
    }
    cout << max(dp[k][n][m][0], dp[k][n][m][1]);
    return 0;
}
