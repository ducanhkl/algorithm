#include <bits/stdc++.h>
#define MAXNUM 1000000007

using namespace std;

unsigned long long f[101][101][101][3];
int w, b, r, _k, m;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(f, 0, sizeof(f));
    cin >> w >> b >> r >> _k >> m;
    for (int i = 1; i <= b; i++)
        f[i][0][0][0] = 1;
    for (int i = 1; i <= r; i++)
        f[0][i][0][1] = 1;
    for (int i = 1; i <= b; i++)
        for (int j = 1; j <= r; j++)
            for (int k = 1; k <= m; k++)
            {
                f[i][j][k][0] = (f[i-1][j][k-1][1] + f[i-1][j][k][0])%MAXNUM;
                f[i][j][k][1] = (f[i][j-1][k-1][0] + f[i][j-1][k][1])%MAXNUM;
            }
    cout << (f[b][r][m][1] + f[b][r][m][0])%MAXNUM;
    return 0;
}
