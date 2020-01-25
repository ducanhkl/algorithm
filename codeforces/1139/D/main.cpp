#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
const long long mod = 1e9+7;

long long m, dp[maxn];

long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    res = res*res%mod;
    if (y%2)
        return res*x%mod;
    return res;
}

long long inv(long long x)
{
    return fast_pow(x, mod-2);
}

int main()
{
    //https://en.wikipedia.org/wiki/Arithmetico%E2%80%93geometric_sequence
    ios_base::sync_with_stdio(false);
    cin >> m;
    for (int i = m; i >= 2; i--)
    {
        long long val = (m/i)*inv(m)%mod;
        dp[i] = (val+val*inv(1-val+mod))%mod;
        for (int j = 2*i; j <= m; j += i)
            dp[i] = (dp[i]-dp[j]+mod*mod)%mod;
    }
    dp[1] = inv(m);
    long long ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans+dp[i])%mod;
    cout << ans;
}
