#include <bits/stdc++.h>

using namespace std;

int a[2000], b[2000], d[2000];
int t, n, m, ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        memset(d, 0, sizeof(d));
        ans = 0;
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        for (int i = 1; i <= m; i++)
        {
            int cur = 0, maxx = 0;
            for (int j = 1; j <= n; j++)
            {
                cur = maxx;
                if (b[j] * 2 <= a[i])
                    maxx = max(maxx, d[j]);
                if (b[j] == a[i])
                    d[j] = max(d[j], cur + 1);
                ans = max(ans, d[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
