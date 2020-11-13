#include <iostream>

using namespace std;

const int maxn = 1e6+100;

long long dp[maxn][3];
int n;
long long r1, r2, r3, d;
long long a[maxn];

void solve()
{
    for (int i = 0; i < maxn; i++)
        dp[i][0] = dp[i][1] = LONG_LONG_MAX;
    dp[1][0] = a[1]*r1 + r3;
    dp[1][1] = min(r2, a[1]*r1 + r1);
    for (int i = 1; i < n; i++)
    {
        // 0 -> 0
        dp[i+1][0] = min(dp[i+1][0], dp[i][0] + d + r1*a[i+1] + r3);


        // 0 -> 1
        dp[i+1][1] = min(dp[i+1][1], dp[i][0] + d + r1*a[i+1] + r1);
        dp[i+1][1] = min(dp[i+1][1], dp[i][0] + d + r2);


        // 1 -> 0
        dp[i+1][0] = min(dp[i+1][0], dp[i][1] + d + r1*a[i+1] + r3 + d + r1 + d);
        dp[i+1][0] = min(dp[i+1][0], dp[i][1] + d + r1*a[i+1] + r1 + d + r1 + d + r1);
        dp[i+1][0] = min(dp[i+1][0], dp[i][1] + d + r2 + d + r1 + d + r1);

        // 1 -> 1
        dp[i+1][1] = min(dp[i+1][1], dp[i][1] + d+r2 + d+r1+d);
        dp[i+1][1] = min(dp[i+1][1], dp[i][1] + d + r1*a[i+1] + r1 + d + r1 + d);
        if (i == n - 1)
            dp[i+1][0] = min(dp[i+1][0], dp[i][1] + d + r1*a[i+1]  + r3 + d + r1);
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    solve();
    cout << dp[n][0];
    return 0;
}
