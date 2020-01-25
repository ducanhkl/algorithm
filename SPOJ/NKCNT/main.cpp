#include <bits/stdc++.h>
#define maxn 6000

using namespace std;

string s[maxn];
long long a[5001][5001];
long long dp[5001][5001];
long long n, m, ans = 0;
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
    {
        char x;
        cin >> x;
        a[i][j] = (int)(x-'0');
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 0)
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1, ans += dp[i][j];
    cout << ans;
    return 0;
}
