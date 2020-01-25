#include <bits/stdc++.h>

using namespace std;

const int maxn = 200, maxm = 100100;
long double dp[maxn][maxm], s = 0;
int n;
long double m;
int x[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        s += x[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1;  i <= n; i++)
    {
        long double tmp = 0;
        for (int j = i; j <= i*m; j++)
        {
            tmp += dp[i-1][j-1];
            if (j-i >= m)
                tmp -= dp[i-1][j-(int)m-1];
            if (j >= x[i])
                dp[i][j] = (tmp - dp[i-1][j-x[i]])/(m-1);
            else
                dp[i][j] = tmp/(m-1);
        }
    }
    long double ans = 0;
    for (int i = n; i < s; i++)
        ans += dp[n][i];
    ans *= (m-1);
    cout << fixed << setprecision(10) << 1+ans;
    return 0;
}
