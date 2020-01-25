#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

int n;
int dp[1<<17][400], sumr = 0, sumb = 0, ans = INT_MAX;
int red[1<<17], blue[1<<17];

struct data
{
    char c;
    int r, b;
} a[maxn];

void reset()
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < 300; j++)
            dp[i][j] = -1;
    dp[0][0] = 0;
}

int main()
{
    memset(red, 0, sizeof(red));
    memset(blue, 0, sizeof(blue));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].c >> a[i].r >> a[i].b, sumr += a[i].r, sumb += a[i].b;
    for (int i = 0; i < (1<<n); i++)
        for (int j = 1; j <= n; j++)
            if (i>>(j-1) & 1)
                {
                    red[i] += (int)(a[j].c == 'R');
                    blue[i] += (int)(a[j].c == 'B');
                    if (blue[0] > 0)
                        n = n;
                }
    reset();
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j <= n*n; j++)
    {
        if (dp[i][j] == -1)
            continue;
        for (int k = 0; k < n; k++)
            if (!(i&(1<<k)))
        {
            int num = k + 1;
            dp[i|(1<<k)][j+min(a[num].r, red[i])] = max(dp[i|(1<<k)][j+min(a[num].r, red[i])], dp[i][j]+min(a[num].b, blue[i]));
        }
    }
    for (int i = 0; i <= n*n; i++)
        if (dp[(1<<n)-1][i] != -1)
            ans = min(ans, max(sumr - i, sumb - dp[(1<<n)-1][i]));
    cout << ans+n;
    return 0;
}
