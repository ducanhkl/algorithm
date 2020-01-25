#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int n;
long long s[maxn];
long long p[maxn], dp[maxn], cnt[maxn];
const long long mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 2; i <= n; i++)
        cin >> p[i];
    for (int i = n; i >= 1; i --)
    {
        s[p[i]] += s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        long long g = __gcd(s[1], s[i]), l = s[1]/g;
        if (l <= n)
            cnt[l] ++;
    }
    for (int i = n; i >= 1; i--)
        for (int j = 2*i; j <= n; j+=i)
            cnt[j] += cnt[i];
    for (int i = n; i >= 1; i--)
        if (cnt[i] == i)
    {
        dp[i] = 1;
        for (int j = 2*i; j <= n; j += i)
            dp[i] = (dp[j]+dp[i])%mod;
    }
    cout << dp[1];
}
