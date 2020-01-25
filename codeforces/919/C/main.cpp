#include <bits/stdc++.h>
#define maxn 2005

using namespace std;

int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
int dem = 0, n, m, k;

int main()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        char x;
        cin >> x;
        if (x == '.')
            a[i][j] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        b[i][j] += b[i][j-1]+a[i][j];
        c[i][j] += c[i-1][j]+a[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        if (j+k-1 <= m)
            if (b[i][j+k-1] - b[i][j-1] == k)
                dem ++;
        if (i+k-1 <= n)
            if (c[i+k-1][j] - c[i-1][j] == k)
                dem++;
    }
    if (k == 1)
        dem /= 2;
    cout << dem;
    return 0;
}
