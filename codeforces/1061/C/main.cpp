#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;
const long long mod = 1e9+7;
int n;
int a[maxn];
long long dp[maxn], ans = 0;

int main()
{
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sqrt(a[i]); j++)
            if (a[i]%j == 0)
            {
                int val = a[i]/j;
                dp[val] = (dp[val]+dp[val-1])%mod;
            }
        for (int j = sqrt(a[i]); j >= 1; j--)
            if (a[i] % j == 0 && j*j != a[i])
                dp[j] = (dp[j]+dp[j-1])%mod;
    }
    for (int i = 1; i < maxn; i++)
        ans = (ans+dp[i])%mod;
    cout << ans;
    return 0;
}
