#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e3+10;
const int mod = 998244353;
int n, k;
int a[maxn];
int dp[maxn][maxn], sum[maxn][maxn], ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a+1, a+n+1);
    for (int i = 1; i <= a[n]/(k-1); i++)
    {
        for (int j = 0; j <= n; j++)
            for (int kk = 0; kk <= k; kk++)
                dp[j][kk] = 0,
                sum[j][kk] = 0;
        for (int j = 1; j <= n; j++)
        {
            dp[j][1] = 1;
            sum[j][1] = (sum[j-1][1] + 1)%mod;
            int pos = upper_bound(a+1, a+n+1, a[j]-i)-a-1;
            for (int kk = 2; kk <= k; kk++)
            {
                dp[j][kk] = (sum[pos][kk-1] + dp[j][kk])%mod;
                sum[j][kk] = (sum[j-1][kk]+dp[j][kk])%mod;
            }
            ans = (ans + dp[j][k])%mod;
        }
    }
    cout << ans;
    return 0;
}
