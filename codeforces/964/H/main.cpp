#include <bits/stdc++.h>

#define ll long long

using namespace std;


const long long maxn = 5e3+5, mod = 1e9+7;
int dp[maxn][2*maxn], a[maxn];
int ans[maxn], pre[maxn];
int n;

long long bin_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = bin_pow(x, y/2);
    res = res*res % mod;
    if (y%2)
        return res*x%mod;
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    pre[0] = 1;
    for (int i = 1; i < n; i++)
        cin >> a[i], pre[i] = ((ll)pre[i-1]*a[i])%mod;
    memset(dp, 0, sizeof(dp));
    for (int i = n; i >= 1; i--)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= n-i; j++)
        {
            dp[i][j] = ((ll)dp[i+1][j-1]*a[i]%mod)%mod;
            ans[j] = ((ll)ans[j]+(ll)dp[i][j]*pre[i-1]%mod)%mod;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2*n-2; j >= 1; j--)
        {
            dp[i][j] = dp[i-1][j-1];
            if (i > 1 && j > 1 && j-2 < n && j <= i+n-2)
                dp[i][j] = (ll)((ll)dp[i][j] + (ll)dp[i][j-2]*(a[i-1]-1)%mod)%mod;
            ans[j] = (ll)((ll)ans[j] + (ll)dp[i][j]*pre[i-1]%mod)%mod;
        }
    }
    long long mod2 = bin_pow(2, mod-2)%mod;
    for (int i = 1; i <= 2*n-2; i++)
        cout << (ll)ans[i]*mod2%mod << " ";
    return 0;
}
