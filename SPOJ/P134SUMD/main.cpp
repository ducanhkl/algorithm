#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int n, c;
long long f[1001][10001], g[1001][10001];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> c;
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    for (int i = 0; i <= n; i++)
        f[i][0] = g[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= c; j++)
    {
        if (j <= (i*(i-1))/2)
            {
                f[i][j] = (g[i-1][j]+f[i][j]+MOD)%MOD;
                if (j-i >= 0)
                    f[i][j] = (f[i][j]-g[i-1][j-i]+MOD)%MOD;
            }
        g[i][j] = (g[i][j] + g[i][j-1] + f[i][j])%MOD;
    }
    cout << f[n][c]%MOD;
    return 0;
}
