#include <bits/stdc++.h>

using namespace std;

const long long L = 840;
long long w;
long long cnt[10], dp[10][L*20], ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int i = 1; i <= 8; i++)
        cin >> cnt[i];
    for (int i = 0; i <= 9; i ++)
        for (int j = 0; j <= L*10; j++)
            dp[i][j] = -1;
    dp[1][0] = 0;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 0; j <= L*8; j++)
        {
            if (dp[i][j] == -1)
                continue;
            long long ma = L/i;
            ma = min(cnt[i], ma);
            for (int k = 0; k <= ma; k++)
            {
                dp[i+1][j + k*i] = max(dp[i+1][j+k*i], dp[i][j] + (cnt[i] - k) / (L/i));
            }
        }
    }
    for (int i = 0; i <= L*8; i++)
    {
        if (i > w || dp[9][i] == -1)
            continue;
        ans = max(ans, i + min(dp[9][i], (w-i)/L)*L);
    }
    cout << ans;
    return 0;
}
