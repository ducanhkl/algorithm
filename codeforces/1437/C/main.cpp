#include <bits/stdc++.h>

using namespace std;


const int maxn = 210;
const int maxc = 410;

int n;
long long dp[maxn][maxc+10];
int a[maxn];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void solve()
{
    sort(a + 1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < maxc; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < maxc; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxc; j++)
        {
            dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + abs(j - a[i]));
        }
    }
    long long ans = INT_MAX;
    for (int i = 1; i <= maxc; i++)
        ans = min(ans, dp[n][i]);
    cout << ans << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        input();
        solve();
    }
    return 0;
}
