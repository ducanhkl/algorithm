#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int n, m;
long long a[maxn], l[maxn], r[maxn];

void solve()
{
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        {
            if (a[i] > m)
            {
                l[i] = a[i];
                l[i] += l[i-1];
            }
        }
    for (int i = n; i >= 1; i--)
        {
            if (a[i] > m)
            {
                r[i] = a[i];
                r[i] += r[i+1];
            }
        }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == m)
        {
            ans = max(ans, l[i-1] + r[i+1]+a[i]);
        }
    }
    cout << ans << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test --)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        solve();
    }
    return 0;
}
