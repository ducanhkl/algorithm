#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
long long a[maxn][maxn], b[maxn][maxn];

void calc(long long &x, long long &y, long long &z, long long &t)
{
    long long arr[] = {x, y, z, t};
    long long ans = LONG_LONG_MAX;
    int id = 1;
    for (int i = 0; i < 4; i++)
    {
        long long res = 0;
        for (int j = 0; j < 4; j++)
        {
            res += abs(arr[i]-arr[j]);
        }
        if (ans > res)
        {
            id = i;
            ans = res;
        }
    }
    x = arr[id], y = arr[id], z = arr[id], t = arr[id];
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        int n, m;
        long long ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                b[i][j] = a[i][j];
            }
        }
        for (int i = 1; i <= (n+1)/2; i++)
        {
            for (int j = 1; j <= (m+1)/2; j++)
            {
                calc(a[i][j], a[n-i+1][j], a[i][m-j+1], a[n-i+1][m-j+1]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ans += abs(b[i][j] - a[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
