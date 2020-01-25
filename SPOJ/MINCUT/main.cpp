#include <bits/stdc++.h>
#define maxn 1006

using namespace std;


long long a[maxn][maxn];
int m, n, k;

long long get(int x, int y, int u, int v)
{
    return a[u][v] + a[x-1][y-1] - a[u][y-1] - a[x-1][v];
}
long long check1(int x, int y, int u, int v)
{
    long long ans = INT_MAX;
    int l = x, r = u;
    while (l < r)
    {
        int mid = (l+r) >> 1;
        if (2*get(x,y, mid, v) - get(x, y, u, v) < 0)
            l = mid+1;
        else r = mid;
        ans = min(ans, min(abs(2*get(x,y, mid, v) - get(x, y, u, v)), min(abs(2*get(x,y, l, v) - get(x, y, u, v)), abs(2*get(x,y, r, v) - get(x, y, u, v)))));
    }
    return ans;
}

long long check2(int x, int y, int u, int v)
{
    long long ans = INT_MAX;
    int l = y, r = v;
    while (l < r)
    {
        int mid = (l+r)>>1;
        if (2*get(x, y, u, mid) - get(x, y, u, mid) < 0)
             l = mid+1;
        else r = mid;
        ans = min(ans, min(abs(2*get(x, y, u, mid) - get(x, y, u, v)), min(abs(2*get(x, y, u, l) - get(x, y, u, v)), abs(2*get(x, y, u, r) - get(x, y, u, v)))));
    }
    return ans;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(a, 0, sizeof(a));
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j], a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    for (int i = 1; i <= k; i++)
    {
        int u, v, x, y;
        cin >> x >> y >> u >> v;
        long long ans = min(check1(x, y, u, v), check2(x, y, u, v));
        cout << ans << endl;
    }
    return 0;
}
