#include <bits/stdc++.h>
#define maxn 1000

using namespace std;


int n;
int a[maxn];
int dp[2][maxn][maxn], e[maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    memset(e, 0, sizeof(e));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (__gcd(a[i], a[j]) > 1)
                    e[i][j] = e[j][i] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (e[i][i+1])
            dp[0][i][i] = 1;
        if (e[i][i-1])
            dp[1][i][i] = 1;
    }
    for (int i = 0; i < n; i++)
        for (int l  = 1; l <= n; l++)
            {
                int r = l+i;
                for (int k = l; k <= r; k++)
                    if ((dp[0][l][k-1] || k == l) && (dp[1][k+1][r] || k == r))
                    {
                        if (e[l-1][k] || l-1 == 0)
                            dp[1][l][r] = 1;
                        if (e[k][r+1] || r+1 == n+1)
                            dp[0][l][r] = 1;
                    }
            }
    if (dp[0][1][n] || dp[1][1][n])
        cout << "YES";
    else cout << "NO";
    return 0;
}
