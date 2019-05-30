#include <bits/stdc++.h>
#define maxn 100002

using namespace std;

int n;
int down[maxn][202], up[maxn][202], dp[maxn][202], down1[maxn][202];
int a[maxn];
long long ans = 0;
const long long mod = 998244353;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(a, 0, sizeof(a));
    memset(down, 0, sizeof(down));
    memset(up, 0, sizeof(up));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = 0;
    dp[0][0] = 1;
    down[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 200; j++) down[i-1][j] = ((long long)down[i-1][j-1]+dp[i-1][j])%mod;
        for (int j = 200; j >= 1; j--) down1[i-1][j] = ((long long)down1[i-1][j+1]+down1[i-1][j])%mod;
        for (int j = 200; j >= 1; j--) up[i-1][j] = ((long long)up[i-1][j+1]+dp[i-1][j])%mod;
        if (a[i] == -1)
        {
            for (int j = 1; j <= 200; j++)
            {
                dp[i][j] = dp[i-1][j];
                dp[i][j] = (dp[i][j] + (long long)down[i-1][j-1])%mod;
                down1[i][j] = down[i-1][j-1];
                if (i >= 1)
                    dp[i][j] = (dp[i][j] + (long long)up[i-1][j+1]-down1[i-1][j+1]+mod)%mod;
            }
        }
        else
        {
            int j = a[i];
            dp[i][j] = dp[i-1][j];
            dp[i][j] = (dp[i][j] + (long long)down[i-1][j-1])%mod;
            down1[i][j] = down[i-1][j-1];
            if (i >= 1)
                dp[i][j] = (dp[i][j] + (long long)up[i-1][j+1]-down1[i-1][j+1]+mod)%mod;
        }
    }
    if (a[n] != -1)
        ans = (dp[n][a[n]]-down[n-1][a[n]-1]+mod)%mod;
    else
        for (int i = 1; i <= 200; i++)
            ans = (ans+dp[n][i]-(long long)down[n-1][i-1]+mod)%mod;
    cout << ans;
    return 0;
}
