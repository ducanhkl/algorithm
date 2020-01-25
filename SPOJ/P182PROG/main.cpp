#include <bits/stdc++.h>

using namespace std;

const int maxn = 202, maxc = 3600;
int n, p, ans = 0;
pair <int, int> a[maxn];
int dp[maxn][maxn][maxc+10], dd[maxn][maxn][maxc+10];

int main()
{
    freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    memset(dd, 0, sizeof(dd));;
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        int cnt2 = 0, cnt5 = 0;
        while (x%2 == 0)
            x /= 2, cnt2++;
        while (x%5 == 0)
            x /= 5, cnt5++;
        a[i].first = cnt5;
        a[i].second = cnt2;
    }
    for (int i = 0; i <= n; i++)
        dd[0][i][0] = 1;
    for (int i = 1; i <= p; i++)
        for (int j = 1; j <= n; j++)
            for (int k = maxc; k >= 0; k--)
    {
        dp[i][j][k] = dp[i][j-1][k];
        dd[i][j][k] = dd[i][j-1][k];
        if (k >= a[j].first && dd[i-1][j-1][k-a[j].first])
        {
            dd[i][j][k] = 1;
            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-a[j].first]+a[j].second);
        }
        ans = max(ans, min(dp[i][j][k], k));
    }
    cout << ans;
    return 0;
}
