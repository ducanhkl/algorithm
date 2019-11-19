#include <bits/stdc++.h>

using namespace std;

int a[101][101], n, m, ans = INT_MAX;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int x = i; x <= n; x++)
                for (int y = j; y <= n; y++)
    {
        int ss = (x-i+1)*(y-j+1);
        if (ss != m)
            continue;
        int s = a[x][y] - a[x][j-1] - a[i-1][y] + a[i-1][j-1];
        ans = min(ans, m-s);
    }
    cout << ans;
    return 0;
}
