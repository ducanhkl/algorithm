#include <bits/stdc++.h>

using namespace std;

int n, m, k;
long long a[600][600], sans = INT_MAX, xans, yans, zans, tans;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(a, 0, sizeof(a));
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
    {
        cin >> a[i][j];
        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    }
    for (int i = 1; i <= n; i++)
        for (int x = i; x <= n; x++)
    {
        int j = 1, y = 1;;
        while (j <= y && y <= m)
        {
            long long sum = a[x][y] - a[i-1][y] - a[x][j-1] + a[i-1][j-1];
            if (sum >= k)
            {
                int s = (x-i+1)*(y-j+1);
                if (s < sans)
                {
                    zans = x;
                    tans = y;
                    xans = i;
                    yans = j;
                    sans = s;
                }
                j ++;
            } else y++;
        }
    }
    if (sans == INT_MAX)
        return cout << -1, 0;
    cout << sans << endl << xans << " " << yans << " " << zans << " " << tans;
    return 0;
}
