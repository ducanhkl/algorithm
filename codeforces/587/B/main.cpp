#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int n, k;
long long ans = 0, dp[maxn], sum[maxn], l;
const long long mod = 1e9+7;
int a[maxn];
pair <int, int> b[maxn];

int main()
{
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    ios_base::sync_with_stdio(false);
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n*k; i++)
        b[i] = {a[i%n], i};
    sort(b, b+n*k);
    for (int i = 0; i < n*k; i++)
        {
            int pos = b[i].second;
            if (pos < n)
                dp[pos] = 1;
            else
                dp[pos] = sum[pos/n-1];
            sum[pos/n] = (sum[pos/n] + dp[pos])%mod;
            if (pos < l)
                ans = (ans+((l-pos-1)/n+1)%mod*dp[pos]%mod)%mod;
        }
    cout << ans;
    return 0;
}
