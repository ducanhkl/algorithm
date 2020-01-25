#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;
int n;
int dp[maxn][maxn][maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
    {
        char x;
        cin >> x;
        if (x == '#')
            dp[i][j][i][j] = 1;
    }
    for (int h = 1; h <= n; h++)
        for (int w = (h==1)+1; w <= n; w++)
    {

        for (int i = 1; i+h-1 <= n; i++)
            for (int j = 1; j+w-1 <= n; j++)
        {
            int ii = i+h-1, jj = j+w-1;
            dp[i][j][ii][jj] = max(h, w) ;
            for (int s = i; s < ii; s++)
                dp[i][j][ii][jj] = min(dp[i][j][ii][jj], dp[i][j][s][jj]+dp[s+1][j][ii][jj]);
            for (int s = j; s < jj; s++)
                dp[i][j][ii][jj] = min(dp[i][j][ii][jj], dp[i][j][ii][s]+dp[i][s+1][ii][jj]);
        }
    }
    cout << dp[1][1][n][n];
}
