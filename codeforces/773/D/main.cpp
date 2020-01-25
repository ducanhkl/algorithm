#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3+10;
int n;
int vis[maxn];
long long f[maxn], a[maxn][maxn], mn = 1LL<<62;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(vis, 0, sizeof(vis));
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < maxn; i++)
        f[i] = 1LL<<62;
    cin >> n;
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
    {
        cin >> a[i][j];
        a[j][i] = a[i][j];
        mn = min(mn, a[i][j]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
    {
        if (i == j)
            continue;
        a[i][j] -= mn;
        f[i] = min(f[i], 2*a[i][j]);
    }
    for (int i = 1; i <= n; i++)
    {
        int t = 0;
        for (int j = 1; j <= n; j++)
            if (f[t] > f[j] && vis[j] == 0)
                t = j;
        vis[t] = 1;
        for (int j = 1; j <= n; j++)
            f[j] = min(f[j], f[t] + a[t][j]);
    }
    for (int i = 1; i <= n; i++)
        cout << f[i] + (n-1)*mn << endl;
    return 0;
}
