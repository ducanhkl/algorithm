#include <bits/stdc++.h>

using namespace std;

const long long maxn = 3e6+100;
const long long maxc = 1e9+7;
long long a, b, k;

long long dp[maxn];

long long get_ans(long long x, long long y)
{
    for (long long i = 0; i < maxn; i++)
        dp[i] = maxc;
    dp[x] = 0;
    for (long long i = x; i > y; i--)
    {
        for (long long j = 2; j <= k; j++)
        {
            long long num = i/j*j;
            dp[num] = min(dp[num], dp[i] + 1);
        }
        dp[i-1] = min(dp[i-1], dp[i] + 1);
    }
    return dp[y];
}

long long __lcm(long long x, long long y)
{
    return x*y/__gcd(x, y);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> k;
    long long lcm = 1;
    for (long long i = 1; i <= k; i++)
    {
        lcm = __lcm(lcm, i);
    }
    long long val = get_ans(lcm, 0);
    long long m1 = a%lcm, m2 = b%lcm, cnt = a/lcm - b/lcm;
    if (m1 < m2)
        m1 += lcm, cnt --;
    long long ans = cnt*val;
    ans += get_ans(m1, m2);
    cout << ans;
    return 0;
}
