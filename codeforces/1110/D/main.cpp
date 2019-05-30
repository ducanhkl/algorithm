#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;
int n, m, res = 0, ans = 0;
int cnt[maxn];
vector<int> dp[maxn][9];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    for (int i = 1; i <= m; i++)
        if (cnt[i] > 6)
    {
        int x = (cnt[i] - 6)/3;
            res += x;
        cnt[i] -= x*3;
    }
    for (int j = 0; j <= cnt[1]; j++)
        {
            dp[1][j].resize(1);
            dp[1][j][0] = j/3;
        }
    for (int i = 2; i <= m; i++)
        for (int j = 0; j <= cnt[i]; j++)
    {
        dp[i][j].resize(cnt[i-1]+1);
        for (int k = 0; k <= cnt[i-1]; k++)
            for (int h = 0; h <= min(j, k); h++)
                if (h <= cnt[i-2])
            {
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][k-h][cnt[i-2]-h]+(j-h)/3+h);
                ans = max(ans, dp[i][j][k]);
            }
    }
    cout << ans + res;
    return 0;
}
