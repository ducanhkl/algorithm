#include <iostream>

using namespace std;


const int maxn = 5e3+100;
const long long mod = 998244353;

int n, m, k;
long long dp[maxn][maxn];

long long fast_pow(long long x, int y)
{
    x %= mod;
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    res *= res;
    res %= mod;
    if (y%2)
        return res*x%mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >>  k;
    dp[0][0] = 1;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i+1][j] = (dp[i+1][j] + dp[i][j]*j%mod)%mod;
            dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]*(n-j)%mod)%mod;
        }
    }
    long long ans = 0;
    long long inv = fast_pow(m, mod-2);
    for (int i = 1; i <= k; i++)
    {
        ans = (ans + dp[k][i]*fast_pow(inv, i))%mod;
    }
    cout << ans;
    return 0;
}
