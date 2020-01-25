#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;
const int maxn = 501;

int n, m;
char a[maxn][maxn];
int dp[2][maxn][maxn];
int tt = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <=m; j++)
            cin >> a[i][j];
    int len = (n+m)/2 +1;
    for (int i = len; i >= 0; i--)
    {
        tt = tt ^ 1;
        memset(dp[tt], 0, sizeof(dp[tt]));
        for (int y1 = 1; y1 <= m; y1++)
            for (int y2 = y1; y2 <= m; y2++)
        {
            int x1 = i+1-y1;
            int x2 = (m+n-i+1)-y2;
            if (x1 < 1 || x2 < 1 || x1 > n || x2 > n || x2 < x1)
                continue;
            if (a[x1][y1] == a[x2][y2])
            {
                if ((y1 == y2 && x2-x1 == 1) || (x2 == x1 && y2 - y1 == 1) || (y1 == y2 && x2 == x1))
                    dp[tt][y1][y2] = 1;
                else
                {
                    long long sum = 0;
                    sum = ((long long)dp[tt^1][y1+1][y2] + (long long)dp[tt^1][y1][y2-1] + (long long)dp[tt^1][y1][y2] + (long long)dp[tt^1][y1+1][y2-1])%mod;
                    dp[tt][y1][y2] = (int)sum;
                }
            } else
            dp[tt][y1][y2] = 0;
        }
    }
    cout << dp[tt^1][1][m];
    return 0;
}
