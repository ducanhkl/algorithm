#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const int maxn = 2e5+100;

int n, k;
int dp[maxn], cnt[maxn], fi[maxn], se[maxn];
int a[maxn];
int ans = 1;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin  >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = fi[a[i]]; j < se[a[i]]; j++)
        {
            if (--cnt[j] == k)
            {
                ans += dp[j];
                ans %= mod;
            }
        }
        for (int j = se[a[i]]; j < i; j++)
        {
            if (++cnt[j] == k+1)
            {
                ans -= dp[j];
                ans += mod;
                ans %= mod;
            }
        }
        ans %= mod;
        dp[i] = ans;
        fi[a[i]] = se[a[i]];
        se[a[i]] = i;
        ans = (ans + dp[i])%mod;
    }
    cout << dp[n];
}
