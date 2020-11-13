#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

const int maxc = (1<<16);
int dp[maxn][maxc+10], dd[10][10], m[10][10], a[10];
int f[maxn];
int n;

void down(int &x, int y)
{
    x = min(x, y);
}

void init()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            if (x == '*')
                f[j] = (f[j] << 1) + 1;
            else
                f[j] = (f[j] << 1);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= 4-i; j++)
        {
            for (int k = 0; k <= 4; k ++)
                for (int h = 0; h <= 4; h++)
            {
                dd[k][h] = 1;
            }
            for (int k = 0; k < j; k++)
                for (int h = 0; h < j; h++)
            {
                dd[k][h+i] = 0;
            }
            for (int k = 3; k >= 0; k--)
                for (int h = 0; h < 4; h++)
            {
                m[i][j] = (m[i][j]<<1) + dd[k][h];
            }
        }
    }
}

void solve()
{
    for (int i = 1; i <= n+1; i++)
    {
        for (int j = 0; j < maxc; j++)
            dp[i][j] = INT_MAX;
    }
    int tt_begin = 0;
    for (int i = 4; i >= 1; i--)
    {
        tt_begin = (tt_begin << 4) + f[i];
    }
    dp[1][tt_begin] = 0;
    for (int i = 1; i <= n+1; i++)
    {
        for (int j = maxc-1; j >= 0; j --)
        {
            if (dp[i][j] == INT_MAX)
                continue;
            if ((j & 15) == 0)
            {
                down(dp[i+1][(j >> 4) |  ((f[i+4]) << 12)], dp[i][j]);
            }
            for (int k = 0; k < 4; k++)
                for (int h = 1; h <= 4-k; h++)
            {
                down(dp[i][j & m[k][h]], dp[i][j] + a[h]);
            }
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    init();
    solve();
    cout << dp[n+1][0];
    return 0;
}
