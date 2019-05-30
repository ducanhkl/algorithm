#include <bits/stdc++.h>
using namespace std;

long long n, f[2501][2501], a[2501], MIN = -1000010, MAX = -MIN;
int  _m[2*1000010], *m = _m + 1000010;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        long long ans = 0;
        memset(f, 0, sizeof(f));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                f[i][j] = 2;
                long long val = a[i]-a[j];
                //cout << m[val] << endl;
                if (val > MIN && val < MAX && m[val] != 0)
                    f[i][j] = max(f[i][j], f[j][m[val]] + 1);
                m[a[j]] = j;
                ans = max(ans, f[i][j]);
            }
            for (int j = 1; j < i; j++)
                m[a[j]] = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
