#include <bits/stdc++.h>

using namespace std;

const int maxn = 1080;
int n, k;
long long mod, ans =0 ;
long long f1[maxn], f2[maxn], dp[maxn][200];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> mod;
    f1[0] = f2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f1[i] = f1[i-1]*10%k;
        f2[i] = f2[i-1]*10%mod;
    }
    for (int i = 1; i <= 9; i++)
        dp[0][i%k] ++;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < k; j++)
            for (int h = 0; h <= 9; h++)
    {
        if (h*f1[i]%k != j)
            dp[i][j] = (dp[i][j] + dp[i-1][((j-h*f1[i]%k)%k+k)%k])%mod;
        if (h*f1[i]%k == j && h != 0)
            dp[i][j] ++, dp[i][j]%=mod;
    }
    for (int i = 0; i < n-1; i++)
        ans = (ans + dp[i][0]*f2[n-i-2]%mod*9%mod)%mod;
    ans = (ans+dp[n-1][0])%mod;
    cout << ans;
    return 0;
}
