#include <bits/stdc++.h>
#define maxn 2000

using namespace std;

int ans = -1;
int a[maxn], n, cur[maxn], dp[maxn][1<<9], id[maxn];
int v[10][maxn],  cnt[maxn];
const long long maxc = 123456;

int calc(int len)
{
    int res = -1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 256; j++)
            dp[i][j] = -maxc;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 256; j++)
    {
        int k = a[i];
        if (j & (1<<(a[i]-1)))
            {
                if (v[a[i]][id[i]-len+1] > 0)
                    dp[i][j] = max(dp[v[a[i]][id[i]-len+1]-1][j^(1<<(a[i]-1))]+len, dp[i][j]);
                if (v[a[i]][id[i]-len]  > 0)
                    dp[i][j] = max(dp[i][j], dp[v[a[i]][id[i]-len]-1][j^(1<<(a[i]-1))]+len+1);
                if (len != 0 && j == 255)
                    res = max(res,dp[i][j]);
                if (len == 0)
                    res = max(res, dp[i][j]);
            }
        dp[i][j]  = max(dp[i-1][j], dp[i][j]);
    }
    ans = max(ans, res);
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
            id[i] = cnt[a[i]];
            v[a[i]][cnt[a[i]]] = i;
        }
    int l = 0, r = 3;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (calc(mid) > 0)
            l = mid+1;
        else r = mid-1;
    }
    cout << ans;
    return 0;
}
