#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3+10;
const long long mod = 998244353;
int n;
long long dp[maxn][maxn], sum[maxn][maxn], a[maxn], inv[maxn];
int cnt[maxn];

long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x%mod;
    long long res = fast_pow(x, y/2);
    res = res*res%mod;
    if (y%2)
        return res*x%mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        inv[i] = fast_pow(i, mod-2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    cnt[0] = 1;
    for (int i = n; i >= 0; i--)
        for (int j = n; j >= 0; j--)
    {
        if (cnt[i] == 0 || n-j == 0)
        {
            sum[i][j] = sum[i+1][j];
            continue;
        }
        dp[i][j] = (dp[i][j]+(cnt[i]-1)*inv[n-j]%mod)%mod;
        dp[i][j] = (dp[i][j]+sum[i+1][j+1]*inv[n-j])%mod;
        sum[i][j] = (sum[i+1][j]+cnt[i]*dp[i][j])%mod;
    }
    cout << dp[0][0];
    return 0;
}
