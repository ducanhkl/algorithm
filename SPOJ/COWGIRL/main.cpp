#include <bits/stdc++.h>

using namespace std;


long long dp[30][1<<16];
int n, m, t;

bool check (int a, int b, long long c)
{
    int x = (a&b);
    int y = ((~a)&(~b))&c;
    return (x&(x>>1)) || (y&(y>>1));
}
long long calc(int x, long long y)
{
    long long s = 1 << y;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < s; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= x; i++)
        for (int j = 0; j < s; j++)
            for (int k = 0; k < s; k++)
                if (!check(j, k, s-1))
                    dp[i][j] += dp[i-1][k];
    long long res = 0;
    for (int i = 0; i < s; i++)
        res += dp[x-1][i];
    return res;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << calc(max(n, m), min(n, m)) << endl;
    }
    return 0;
}
