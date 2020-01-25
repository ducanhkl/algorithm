#include <bits/stdc++.h>

using namespace std;


const long long maxn = 500, mod = 1e9+7;
long long dp[maxn][maxn];
int n;

int main()
{
    cin >> n;
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
        {
            if (j+k-1 > n)
                break;
            long long tmp = dp[i-1][j]*dp[i-1][k]%mod;
            dp[i][j+k+1] = (dp[i][j+k+1]+tmp)%mod;
            dp[i][j+k] = (dp[i][j+k]+tmp*j*2%mod+tmp*k*2%mod+tmp)%mod;
            dp[i][j+k-1] = (dp[i][j+k-1]+tmp*(j+k)%mod*(j+k-1)%mod)%mod;
        }
    }

    cout << dp[n][1];
    return 0;
}
