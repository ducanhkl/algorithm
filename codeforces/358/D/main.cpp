#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3+100;
int n;
long long a[maxn], b[maxn], c[maxn], dp[maxn][maxn];

int main()
{
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    dp[1][0] = a[1], dp[1][1] = b[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i-1][0] + b[i], dp[i-1][1] + a[i]);
        dp[i][1] = max(dp[i-1][0] + c[i], dp[i-1][1] + b[i]);
    }
    cout << dp[n][0];
    return 0;
}
