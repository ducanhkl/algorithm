#include <bits/stdc++.h>

using namespace std;

char a[4000][300];
int n, m;
int f[30][3200][3200], ans = 0;
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] != '.')
    {
        int _i = i, _j = j;
        while (_i < m && _j < n)
        {
            _i++, _j++;
            if (a[_i][_j] == a[i][j])
            {
                ans += f[(int)(a[i][j]-'a')][i+j][_i+_j];
                f[(int)(a[i][j]-'a')][i+j][_i+_j]++;
            }
        }
    }
    cout << ans;
    return 0;
}
