#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;
string s, t;
int dp[maxn][maxn];
char a[maxn], b[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    cin >> t;
    int n = s.length();
    int m = t.length();
    for (int i = 1; i <= n; i++)
        a[i] = s[i-1];
    for (int i = 1; i <= m; i++)
        b[i] = t[i-1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        dp[i][j] = max(dp[i-1][j-1], max(dp[i][j-1], dp[i-1][j]));
        if (a[i] == b[j])
            dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
    }
    cout << dp[n][m];
    return 0;
}
