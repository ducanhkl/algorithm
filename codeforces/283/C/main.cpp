#include <bits/stdc++.h>

using namespace std;

int n, q, nextx[500], dd[500], a[500], b[500], cnt = 0;
long long t, u, v, dp[100005], tt = 0;
long long mod = 1e9+7;


int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n >> q >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        nextx[u] = v;
        dd[v] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (dd[i] == 0)
    {
        long long s = 0, j = i;
        while (j)
        {
            tt += s;
            s += a[j];
            b[++cnt] = s;
            j = nextx[j];
        }
    }
    if (tt > t)
        return cout << 0, 0;
    dp[tt] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = b[i]; j <= t; j++)
            dp[j] = (dp[j] + dp[j-b[i]])%mod;
    cout << dp[t];
    return 0;
}
