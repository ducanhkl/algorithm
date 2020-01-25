#include <bits/stdc++.h>
#define maxn 1006

using namespace std;
int n;
long long a[maxn][maxn], sc[maxn][maxn], sh[maxn][maxn], ans = 0, h, c;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    memset(sh, 0, sizeof(sh));
    memset(sc, 0, sizeof(sh));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sh[i][j] = sh[i][j-1] + a[i][j], sc[i][j] = sc[i-1][j] + a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans = max(ans, sh[i][n]+sc[i][n] - a[n][j]*2LL);
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
    {
        h = 0;
        for (int k = 1; k <= n; k++)
        {
            long long res = h + sc[n][k] - a[i][k] - 2*a[j][k];
            ans = max(ans, res);
            long long hh = sh[i][n] + sh[j][n] + sc[n][k] - 2*a[i][k] - a[j][k];
            h = max(h, hh);
            if (k != 1)
                ans = max(ans, hh);
        }
        h = 0;
        for (int k = 1; k <= n; k++)
        {
            long long res = h + sc[n][k] - 2*a[i][k] - a[j][k];
            ans = max(ans, res);
            long long hh = sh[i][n] + sh[j][n] + sc[n][k] - a[i][k] - 2*a[j][k];
            h = max(h, hh);
            if (k != 1)
                ans = max(ans, hh);
        }
        h = 0;
        for (int k = 1; k <= n; k++)
        {

            long long res = h + sh[k][n] - a[k][i] - 2*a[k][j];
            ans = max(ans, res);
            long long hh = sc[n][i] + sc[n][j] + sh[k][n] - 2*a[k][i] - a[k][j];
            h = max(h, hh);
            if (k != 1)
                ans = max(ans, hh);
        }
        h = 0;
        for (int k = 1; k <= n; k++)
        {

            long long res = h + sh[k][n] - 2*a[k][i] - a[k][j];
            ans = max(ans, res);
            long long hh = sc[n][i] + sc[n][j] + sh[k][n] - a[k][i] - 2*a[k][j];
            h = max(h, hh);
            if (k != 1)
                ans = max(ans, hh);
        }
        if (i == 3 && j == 4)
            n = 4;
        for (int k = 1; k < n; k++)
        {
            ans = max(ans, sh[i][n]+sh[j][n]+sc[n][k]-2*a[i][k]-2*a[j][k]);
            ans = max(ans, sc[n][i]+sc[n][j]+sh[k][n]-2*a[k][i]-2*a[k][j]);
        }
    }
    cout << ans;
    return 0;
}
