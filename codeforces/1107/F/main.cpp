#include <bits/stdc++.h>

using namespace std;

const int maxn = 600;

struct data {
    long long a;
    long long b;
    long long k;
};

int n;
long long dp[maxn][maxn];
data e[maxn];

bool cmp(data x, data y)
{
    return x.b > y.b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> e[i].a >> e[i].b >> e[i].k;
    sort(e+1, e+n+1, cmp);
    for (int i = 1; i <= n;i ++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j > 0)
                dp[i][j] = max(dp[i][j],
                            dp[i-1][j-1] + e[i].a - (j-1)*e[i].b);
            dp[i][j] = max(dp[i][j], dp[i-1][j] + e[i].a - e[i].k*e[i].b);
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[n][i]);
    cout << res;
    return 0;
}
