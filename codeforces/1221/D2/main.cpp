#include <bits/stdc++.h>

using namespace std;


const long long maxn = 3e5+100, maxc = 1e18-100;

int n, a[maxn], b[maxn];
long long dp[maxn][4];

void solve()
{
    a[0] = -100;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            dp[i][j] = maxc;
            for (int k = 0; k <= 2; k++)
            {
                if (a[i-1] + k == a[i] + j)
                    continue;
                dp[i][j] = min(dp[i][j], dp[i-1][k] + b[i]*j);
            }
        }
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i] >> b[i];
        solve();
    }
    return 0;
}