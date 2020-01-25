#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
const unsigned long long maxc = 1e19;
int n, m;
unsigned long long b, dp[(1<<22)], ans = maxc;

struct data
{
    long long x, k;
    int m;
    int tt;
} a[maxn];

bool cmp(data x, data y)
{
    return x.k < y.k;
}

void solve()
{
    int val = (1LL << m)-1;
    for (int i = 0; i <= val; i++)
        dp[i] = maxc;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = val; j >= 0; j--)
            {
                if (dp[j] == maxc)
                    continue;
                int jj = j | a[i].tt;
                dp[jj] = min(dp[jj], dp[j] + a[i].x);
            }
        ans = min(ans, dp[val]+a[i].k*b);
    }
    return (void)0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].k >> a[i].m;
        for (int j = 1; j <= a[i].m; j++)
        {
            int x;
            cin >> x;
            a[i].tt |= a[i].tt | (1<<(x-1));
        }
    }
    sort (a+1, a+n+1, cmp);
    solve();
    if (ans == maxc)
        cout << -1;
    else
        cout << ans;
    return 0;
}
