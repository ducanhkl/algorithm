#include <bits/stdc++.h>

using namespace std;

const int maxn = 600;
int n;
long long dp[maxn][maxn];
char a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = INT_MAX;
    for (int i = 1; i <= n; i++)
        dp[i][i] = 1;
    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= n-len+1; i++)
    {
        int j = i+len-1;
        for (int k = i; k <= j-1; k++)
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] - (int)(a[k] == a[j]));
    }
    cout << dp[1][n];
    return 0;
}
