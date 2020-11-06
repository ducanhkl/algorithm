#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3+100;
int n, m;
long long ans = 0;
int d[maxn][maxn], dp[maxn][maxn];
char a[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("inp.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1;i <= n; i++)
        for (int j = 1; j <= m; j ++)
    {
        cin >> a[i][j];
        // cout << a[i][j] << " ";
        if (a[i][j] == a[i-1][j])
            d[i][j] = d[i-1][j]+1;
        else
            d[i][j] = 1;
        if (a[i][j] == a[i-1][j-1] && a[i-1][j+1] == a[i][j])
            dp[i][j] = min(
                            min(dp[i-1][j-1], dp[i-1][j+1])+1,
                           (d[i][j]+1)/2
                        );
        else
            dp[i][j] = 1;
        ans += dp[i][j];
        // cout << d[i][j] << endl;
    }
    cout << ans;
    return 0;
}
