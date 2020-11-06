#include <bits/stdc++.h>

using namespace std;


const int maxn = 100;
const long long mod = 1e9+7;

char s[maxn];
long long dp[maxn][2];
long long p[maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    int n;
    ios_base::sync_with_stdio(false);
    long long ans = 0;
    p[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        p[i] = p[i-1]*2LL;
        p[i] %= mod;
    }
    while(cin >> s[++n]){
        ans = ans*10 + (s[n] - '0');
        ans %= mod;
    };
    n--;
    for (int i = 1; i <= n; i++)
    {
        s[i] -= '0';
        dp[i][0] = (dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1] = (dp[i-1][1]*10%mod + p[i-1]*s[i]%mod)%mod;
    }
    ans = ((dp[n][0] + dp[n][1])%mod - ans + mod) % mod;
    cout << ans;
    return 0;
}
