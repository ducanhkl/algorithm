#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100, mod = 1e9+7;
int dp[maxn][20][2];
int n;


long long f(int x, int y)
{
    long long ans = (1<<x);
    if (y)
        ans*=3;
    return n/ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    int maxBit = 0;
    while ((1<<(maxBit+1)) <= n)
    {
        maxBit ++;
    }
    dp[1][maxBit][0] = 1;
    if ((1<<(maxBit-1))*3 <= n)
        dp[1][maxBit-1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x <= maxBit; x++)
        {
            for (int y = 0; y <= 1; y++)
            {
                dp[i+1][x][y] = (dp[i+1][x][y] + dp[i][x][y]*(f(x, y)-i)%mod)%mod;
                if (x)
                    dp[i+1][x-1][y] = (dp[i+1][x-1][y] + dp[i][x][y]*(f(x-1, y)-f(x, y))%mod)%mod;
                if (y)
                    dp[i+1][x][y-1] = (dp[i+1][x][y-1] + dp[i][x][y]*(f(x, y-1)-f(x, y))%mod)%mod;
            }
        }
    }
    cout << dp[n][0][0];
    return 0;
}
