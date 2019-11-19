#include <bits/stdc++.h>
#define maxn 1000

using namespace std;


long long dp[maxn][10*maxn], c[maxn], f[maxn], h[maxn];
int dd[10000006], d[1000006];
long long ans = 0;
int n, k;


int main()
{
    memset(dd, 0, sizeof(dd));
    memset(d, 0, sizeof(d));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n*k; i++)
        {
            int x;
            cin >> x;
            dd[x] ++;
        }
    for (int i = 1; i<= n; i++)
    {
        int x;
        cin >> x;
        d[x] ++;
    }
    for (int i = 1; i <= k; i++)
        cin >> h[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n*k; j++)
            for (int t = 0; t <= min(k, j); t++)
                dp[i][j] = max(dp[i][j], dp[i-1][j-t] + h[t]);
    for (int i = 1; i <= 1e5+10; i++)
        ans += dp[d[i]][dd[i]];
    cout << ans;
    return 0;
}
