#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100, maxm = 22;

int n, m;
long long dp[(1<<maxm)+100];
int g[maxm][maxm];
char a[maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] -= 'a';
    for (int i = 1; i < n; i++)
    {
        g[a[i]][a[i+1]] ++;
        g[a[i+1]][a[i]] ++;
    }
    dp[0] = 0;
    for (int i = 1; i < (1<<m); i++)
    {
        dp[i] = 1e12;
        long long c = 0;
        for (int j = 0; j < m; j++)
            for (int k = j+1; k < m; k++)
        {
            if (((i>>j)&1) ^ ((i>>k)&1))
                c += g[j][k];
        }
        for (int j = 0; j < m; j++)
        {
            if ((i>>j)&1)
                dp[i] = min(dp[(i^(1<<j))]+c, dp[i]);
        }
    }
    cout << dp[(1<<m)-1];
    return 0;
}
