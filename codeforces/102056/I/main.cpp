#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        reset(0);
        dp[1][1][n] = a[1];
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
                for (int k = n; k <= (i+1)*(2*n-i)/2; k++)
            {
                if (dp[(i+1)%2][j][k] == -1)
                    continue;
                dp[i%2][j+1][k+n-i] = max(dp[i%2][j+1][k+n-i], dp[(i+1)%2][j][k]+a[i])
            }
        }
    }
    return 0;
}
