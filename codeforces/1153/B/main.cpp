#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;


int n, m, h;
int a[maxn], b[maxn], d[maxn][maxn], ck[maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> h;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> d[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            ck[j][i] = a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ck[i][j] = min(ck[i][j], b[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (d[i][j] == 0)
                ck[i][j] = 0;
    for (int i = 1; i <= n; i++, cout << endl)
        for (int j = 1; j <= m; j++)
            cout << ck[i][j] << " ";
    return 0;
}
