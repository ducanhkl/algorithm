#include <bits/stdc++.h>
#define MAXNUM 1000000007

using namespace std;

unsigned long long f[1001][10001], g[1001][10001];
int n, s, a[1001];

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0][0] = 1;
    g[n+1][0] = 1;
    for (int i = 1; i <= n+1; i++)
        for (int j = 0; j <= s; j++)
            if (j >= a[i])
                f[i][j] = (f[i-1][j] + f[i-1][j-a[i]])%MAXNUM;
            else f[i][j] = f[i-1][j];
    for (int i = n; i >= 0;i --)
        for (int j = 0; j <= s; j++)
            if (j >= a[i])
                g[i][j] = (g[i+1][j] + g[i+1][j-a[i]])%MAXNUM;
            else g[i][j] = g[i+1][j];
    for (int i = 1; i <= n; i++)
    {
        unsigned long long ans = 0LL;
        for (int j = 0; j <= s-a[i]; j++)
            ans = (ans + (f[i-1][j]*g[i+1][s-j-a[i]])%MAXNUM)%MAXNUM;
        cout << ans << " ";
    }
    return 0;
}
