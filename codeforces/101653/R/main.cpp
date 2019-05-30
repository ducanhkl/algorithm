#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;

long long dp[maxn][20], dp2[maxn][20];
int test;
int n, a[maxn];
string s;

int solve()
{
    long long ans = 0;
    memset(dp, 0, sizeof(dp));
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i <= n ; i++)
        a[i]  = s[i-1] - '0';
    for (int i = 2; i <= n; i++)
        if (a[i] < a[i-1])
            return cout << -1 << endl, 0;
    for (int i = 0; i <= 9; i++)
        dp[n][i] = 1;
    for (int i = n-1; i >= 1; i--)
        for (int j = 0; j <= 9; j++)
            for (int k = j; k <= 9; k++)
                dp[i][j] += dp[i+1][k];
    int ma = 0;
    for (int i = 1; i <= n; i++)
    {
        long long res = 0;
        for (int j  = ma; j < a[i]; j++)
            res += dp[i][j];
        ans += res;
        ma = max(ma, a[i]);
    }
    cout << ans << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> test;
    while (test --)
    {
        solve();
    }
    return 0;
}
