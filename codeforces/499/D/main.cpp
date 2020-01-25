#include <bits/stdc++.h>
#define maxn 5006

using namespace std;

double p[maxn], dp[maxn][maxn], ans = 0;
int t[maxn], n, T;


int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    memset(p, 0, sizeof(p));
    ios_base::sync_with_stdio(false);
    cin >> n >> T;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> t[i];
        p[i]/=100;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        double res = 0, q = pow(1-p[i], t[i]-1);
        for (int j = 0; j <= T; j++)
        {
            if (j >= t[i])
            {
                dp[i][j] += dp[i-1][j-t[i]]*q;
                res -= dp[i-1][j-t[i]]*q;
            }
            dp[i][j] += res*p[i];
            res *= (1-p[i]);
            if (j < T)
                res += dp[i-1][j];
        }
        dp[i-1][T] += res;
    }
    for (int i = 1; i <= n; i++)
        ans += dp[i][T]*i;
    for (int i = 1; i < T; i++)
        ans += dp[n][i]*n;
    cout << fixed << setprecision(10) << ans;
}
