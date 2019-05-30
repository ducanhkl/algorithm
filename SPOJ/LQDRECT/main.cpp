#include <bits/stdc++.h>

using namespace std;


unsigned long long ans = 0;
int m, n;
int dd[2000][500], a[2000][500];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    memset(dd, 0, sizeof(dd));
    ans = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 1)
                for (int k = j+1; k <= n; k++)
                    if (a[i][k] == 1)
                {
                    ans += dd[j][k];
                    dd[j][k] ++;
                }
    cout << ans;
    return 0;
}
