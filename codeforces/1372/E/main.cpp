#include <bits/stdc++.h>

using namespace std;

const int maxn = 120;
int n, m;
int mi[maxn][maxn], ma[maxn][maxn], dp[maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int q;
        cin >> q;
        for (int j = 1; j <= q; j++)
        {
            int x, y;
            cin >> x >> y;
            for (int k = x; k <= y; k++)
            {
                mi[i][k] = x;
                ma[i][k] = y;
            }
        }
    }
    for (int len = 1; len <= m; len ++)
    {
        for (int i = 1; i <= m; i++)
        {
            int j = i+len-1;
            if (j > m)
                break;
            for (int k = i; k <= j; k++)
            {
                int cnt = 0;
                for (int r = 1; r <= n; r++)
                {
                    if (mi[r][k] >= i && ma[r][k] <= j)
                    {
                        cnt ++;
                    }
                }
                dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + cnt*cnt);
            }
        }
    }
    cout << dp[1][m];
    return 0;
}
