#include <bits/stdc++.h>
#define maxn 101
using namespace std;

int a[maxn][maxn], colum[maxn][maxn], row[maxn][maxn], colum1[maxn][maxn], row1[maxn][maxn], n, m;
long long p[maxn], ans = 0;
int main()
{
    memset(colum, 0, sizeof(colum1));
    memset(row, 0, sizeof(row));
    memset(colum1, 0, sizeof(colum1));
    memset(row1, 0, sizeof(row1));
    //freopen("inp.txt", "r", stdin);
    cin >> n >> m;
    for (int i =1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    p[0] = 1;
    for (int i = 1; i <= 50; i ++)
        p[i] = p[i-1] * 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        if(a[i][j] == 1)
            colum1[i][j] ++, row1[i][j] ++;
        if(a[i][j] == 0)
            colum[i][j] ++, row[i][j]++;
        colum[i][j] += colum[i-1][j];
        colum1[i][j] += colum1[i-1][j];
        row[i][j] += row[i][j-1];
        row1[i][j] += row1[i][j-1];
    }
    for (int i = 1; i <= n; i++)
        ans += p[row[i][m]] + p[row1[i][m]] - 2;
    for (int i = 1; i <= m; i++)
        ans += p[colum[n][i]] + p[colum1[n][i]] - 2;
    cout << ans - n*m;
    return 0;
}
