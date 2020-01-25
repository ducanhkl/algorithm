#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;
int t, m, n, x, y, b;
int cnt[maxn], f[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int u;
        cin >> u;
        cnt[u] ++;
    }
    for (int i = 1; i < maxn; i++)
        if (cnt[i] != 4*i)
    {
        x = i;
        break;
    }
    for (int i = maxn; i > 0; i--)
        if (cnt[i])
    {
        b = i;
        break;
    }
    for (int n = 1; n <= t; n++)
        if (t%n == 0)
            {
                m = t/n;
                y = n+m-x-b;
                memset(f, 0, sizeof(f));
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= m; j++)
                        f[abs(x-i)+abs(y-j)]++;
                bool check = true;
                for (int i = 0; i < maxn; i++)
                    if (f[i] != cnt[i])
                {
                    check = false;
                    break;
                }
                if (check)
                {
                    cout << n << " " << m << endl;
                    cout << x << " "  << y;
                    return 0;
                }
            }
    cout << -1;
    return 0;
}
