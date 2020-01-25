#include <bits/stdc++.h>

using namespace std;


const int maxn = 60;
int n, h, m;
long long dp[maxn][maxn][maxn], cost[maxn][maxn][maxn][maxn];
int l[maxn], r[maxn], c[maxn], x[maxn];

long long calc(int lf, int rg, int hg)
{
    if (rg < lf)
        return 0;
    long long ans = 0;
    if (dp[lf][rg][hg] != -1)
    {
        return dp[lf][rg][hg];
    }
    for (int len = 0; len <= hg; len++)
    {
        for (int mid = lf; mid <= rg; mid ++)
        {
            ans = max(ans, calc(lf, mid-1, len) + calc(mid+1, rg, len) + len*len - cost[lf][rg][mid][len]);

        }
    }
    dp[lf][rg][hg] = ans;
    return ans;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> h >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i] >> x[i] >> c[i];
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int k = i; k <= j; k++)
                for (int len = 0; len <= h; len ++)
            {
                for (int q = 1; q <= m; q++)
                {
                    if (i <= l[q] && l[q] <= k && k <= r[q] && r[q] <= j &&  len > x[q])
                    {
                        cost[i][j][k][len] += c[q];
                    }
                }
            }
        }
    }
    long long ans = calc(1, n, h);
    cout << ans;
    return 0;
}
