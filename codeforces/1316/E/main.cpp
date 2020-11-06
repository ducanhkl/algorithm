#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

struct data {
    int v;
    long long s[10];
};

int n, p, k;
data a[maxn];
long long dp[maxn][150];

bool cmp(data x, data y)
{
    return x.v > y.v;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].v;
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < 150; j++)
        {
            dp[i][j] = LONG_LONG_MIN;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
            cin >> a[i].s[j];
    }
    sort(a+1, a+n+1, cmp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int tt = 0; tt < (1<<p); tt++)
        {
            dp[i][tt] = dp[i-1][tt];
            int cnt = 0;
            for (int j = 0; j < p; j++)
            {
                if ((1 << j) & tt)
                {
                    cnt ++;
                    dp[i][tt] = max(dp[i][tt], dp[i-1][tt^(1<<j)] + a[i].s[j+1]);
                }
            }
            if (i <= cnt+k)
            {
                dp[i][tt] = max(dp[i][tt], dp[i-1][tt] + a[i].v);
            }
        }
    }
    cout << dp[n][(1 << p) - 1];
    return 0;
}
