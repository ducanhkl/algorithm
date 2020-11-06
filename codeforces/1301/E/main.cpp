#include <bits/stdc++.h>

using namespace std;


const int maxn = 505;

int n, m, q;
int a[maxn][maxn], dp[maxn][maxn][maxn];

bool check(int r1, int c1, int r2, int c2, int sz)
{
    if (sz == 0)
        return true;
    r2 -= 2*sz-1;
    c2 -= 2*sz-1;
    if (r2 < r1 || c2 < c1)
        return false;
    if (dp[r2][c2][sz] - dp[r1-1][c2][sz] - dp[r2][c1-1][sz] + dp[r1-1][c1-1][sz] > 0 )
        return true;
    return false;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            if (x == 'R')
                a[i][j] = 0;
            if (x == 'G')
                a[i][j] = 1;
            if (x == 'Y')
                a[i][j] = 2;
            if (x == 'B')
                a[i][j] = 3;
        }
    }
    for (int i = 0; i <= n+1; i++)
        a[i][0] = a[i][m+1] = -1;
    for (int i = 0; i <= m+1; i++)
        a[0][i] = a[n+1][i] = -1;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            int p = 1;
            int ck = true;
            int i = x, j = y;
            if (p == 1 && x == 2 && y == 8)
            {
                n++;
                n--;
            }
            while (ck)
            {
                for (int k = 0; k < p; k++)
                {
                    if (!(a[i+k][j] == 0 && a[i][j+k] == 0))
                        ck = false;
                    if (!((a[i+k][j+p] == 1 && a[i][j+p+k]) == 1))
                        ck = false;
                    if (!(a[i+p+k][j] == 2 && a[i+p][j+k] == 2))
                        ck = false;
                    if (!(a[i+p+k][j+p] == 3 && a[i+p][j+p+k] == 3))
                        ck = false;
                }
                if (!ck)
                    break;
                dp[i][j][p] = 1;
                i--, j--, p++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= maxn; k++)
                dp[i][j][k] += dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
    for (int i = 1; i <= q; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int l = 0, r = maxn;
        int res = 0;
        while (l <= r)
        {
            int mid = (l+r)/2;
            if (check(r1, c1, r2, c2, mid))
                l = mid+1, res = mid;
            else
                r = mid-1;
        }
        cout << 4*res*res << endl;
    }
    return 0;
}
