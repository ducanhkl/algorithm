#include <bits/stdc++.h>
#define maxn 4006

using namespace std;

char a[maxn][maxn];
int n, k;
int dp[maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 0; i <= n; i++)
        dp[0][i] = dp[i][0] = 9999;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            {
                if (i+j!=2)
                    dp[i][j]= min(dp[i-1][j], dp[i][j-1]) + (int)(a[i][j] != 'a');
                else
                    dp[i][j] = (int)(a[i][j] != 'a');
                if (dp[i][j] <= k)
                    a[i][j] = 'a';
            }
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for (int step = 1; step < 2*n; step++)
    {
        char res = 'z';
        int mi = max(1, step-n+1);
        for (int i = mi; i <= step-mi+1; i++)
            if (dp[i][step-i+1])
                res = min(res, a[i][step-i+1]);
        cout << res;
        for (int i = mi; i <= step-mi+1; i++)
            if (dp[i][step-i+1] && a[i][step-i+1] == res)
                dp[i+1][step-i+1] = dp[i][step-i+2] = 1;
    }
    return 0;
}
