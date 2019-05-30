#include <bits/stdc++.h>
#define maxn 55

using namespace std;

int n, m, ans = 0;
int cost[maxn+1], res[maxn+1], a[maxn];
int g[maxn+1][maxn+1], f[55][3000];
int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(res, 0, maxn);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x;
            cin >> cost[x];
            g[0][x] = cost[x];
        }
    for (int i = 1; i <= maxn; i++)
        for (int j = 1; j <= maxn; j++)
            for (int k = 1; k <= maxn; k++)
                if (j >= k && j >= i)
                    g[i][j] = max(g[i][j], g[i-1][j-k] + cost[k]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 2501; j++)
            for (int k = 0; k <= maxn; k++)
                if (k <= j)
                    f[i][j] = max(f[i][j], f[i-1][j-k]+g[k][a[i]]);
    for (int i = 1; i <= 2500; i++)
        ans = max(ans, f[n][i]-(i*(i+1))/2);
    cout << ans;
    return 0;
}
