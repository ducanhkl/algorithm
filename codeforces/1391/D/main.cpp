#include <bits/stdc++.h>

using namespace std;

const int maxn = 5;
const int maxm = 1e6+100;

int n, m;
char s[maxn][maxm];
int  a[maxm];
int dp[maxm][(1 << maxn)];

bool check(int i, int j)
{
    if (n == 2) {
        return ((__builtin_popcount(i) + __builtin_popcount(j))%2);
    } else {
        return (
                (__builtin_popcount(i>>1) + __builtin_popcount(j>>1))%2 &&
                (__builtin_popcount(i&3) + __builtin_popcount(j&3))%2
                );
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if (n >= 4)
    {
        cout << -1;
        return 0;
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j<= m; j++)
        {
            cin >> s[i][j];
            s[i][j] -= '0';
        }
    }
    for (int i = 1; i <= m; i++)
    {
        a[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            a[i] += s[j][i] << (j-1);
        }

    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < (1 << n); j ++)
        {
            dp[i][j] = INT_MAX;
            int cost = __builtin_popcount(j ^ a[i]);
            for (int k = 0; k < (1<<n); k ++)
            {
                if (i == 1 || check(k, j))
                    dp[i][j] = min(dp[i][j],
                                dp[i-1][k] + cost);
            }
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < (1 << n); i++)
        res = min(dp[m][i], res);
    if (res == INT_MAX)
        cout << -1;
    else
        cout << res;
    return 0;
}
