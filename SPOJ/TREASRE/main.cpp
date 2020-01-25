#include <bits/stdc++.h>

using namespace std;

long long a[3001][3001], dp[3001][3001], maxx[3001][3001];
long long n, ans = 0LL;

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i; j >= 1; j--)
            cin >> a[i][j], a[i][j] += a[i-1][j];
    for (int j = 1; j <= n; j++)
        {
            for (int i = j; i <= n; i++)
                dp[i][j] = maxx[i-1][j-1] + a[i][j];
            for (int i = n; i >= j; i--)
                maxx[i][j] = max(dp[i][j], maxx[i+1][j]), ans = max(maxx[i][j], ans);
        }
    cout << ans << endl;
    return 0;
}
