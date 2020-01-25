#include <bits/stdc++.h>
#define maxn 1004

using namespace std;

int n, m, ans = 0;
int dp1[maxn][maxn], dp0[maxn][maxn], a[maxn][maxn], b[maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
                cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] = !a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] != 0)
                dp1[i][j] = min(dp1[i][j-1], min(dp1[i-1][j], dp1[i-1][j-1]))+1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (b[i][j] != 0)
            dp0[i][j] = min(dp0[i][j-1], min(dp0[i-1][j], dp0[i-1][j-1]))+1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, max(dp1[i][j], dp0[i][j]));
    cout << ans;
    return 0;
}
