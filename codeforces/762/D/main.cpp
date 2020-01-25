#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

long long a[maxn][3], f[maxn], g[maxn], h[maxn], s[maxn];
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[j][i];
    for (int i = 1; i <= n; i++)
        g[i] = h[i] = f[i] = -1e17;
    for (int i = 1; i <= n; i++)
        s[i] = s[i-1]+a[i][0]+a[i][1]+a[i][2];
    f[1] = a[1][0];
    g[1] = s[1];
    h[1] = a[1][0] + a[1][1];
    long long u = max(0LL, f[1] - s[1]), d = 0;
    for (int i = 2; i <= n; i++)
    {
        f[i] = max(f[i-1] + a[i][0], s[i] + d);
        f[i] = max(f[i], h[i-1] + a[i][1] + a[i][0]);
        g[i] = max(g[i-1]+a[i][2], s[i] + u);
        g[i] = max(g[i], h[i-1] + a[i][1]+a[i][2]);
        h[i] = max(h[i-1], max(f[i-1] + a[i][0], g[i-1]+a[i][2]))+a[i][1];
        u = max(u, f[i] - s[i]);
        d = max(d, g[i] - s[i]);
    }
    cout << g[n];
    return 0;
}
