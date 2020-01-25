#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        memset(dp, 0 , sizeof(dp));
        memset(p, 0, sizeof(p))
        for (int i = 1; i <= n; i++)
            dp[1][0][i] = dp[1][1][i] =  1;
        for (int i = 2; i <= n; i++)

    }
    return 0;
}
