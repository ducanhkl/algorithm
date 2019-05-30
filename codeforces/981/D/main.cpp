//https://anotepad. com/notes/96mfkf
//https://yespornplease.com/

#include <bits/stdc++.h>
#define maxn 100

using namespace std;

long long dp[maxn][maxn];
int n, k;
long long a[maxn], res, ans;

bool check(long long x)
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = i; j <= n; j++)
            for (int l = j-1; l >= i-1; l--)
    {
        long long tong = a[j] - a[l];
        dp[i][j] = (dp[i][j] | (dp[i-1][l] && ((tong & x) == x)));
    }
    return dp[k][n];
}

int main()
{
    memset(dp, 0, sizeof(dp));
    //freopen("inp.ttx", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i-1];
    for (int i = 56; i >= 0; i--)
    {
        res = ans | (1LL << i);
        if (check(res))
            ans = res;
    }
    cout << ans;
    return 0;
}
