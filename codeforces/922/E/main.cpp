#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, w, b, x, ans = 0;
long long f[maxn], g[maxn], c[maxn], cost[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >>  n >> w >> b >> x;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];
    for (int i = 0; i <= 100000; i++) f[i] = g[i] = -1;
    f[0] = w;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 10000; j++)
            if (f[j] != -1)
                for (int k = 0; k <= c[i]; k++)
                    if (f[j] >= cost[i]*k)
                        g[j+k] = max(g[j+k], min(f[j]-cost[i]*k+x,(long long)b*(j+k) + w));
        for (int j = 0; j <= 10000; j++)
            f[j] = g[j], g[j] = -1;
    }
    for (int i = 0; i <= 10000; i++)
        if (f[i] != -1)
            ans = i;
    cout << ans;
    return 0;
}
