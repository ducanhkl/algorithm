#include <bits/stdc++.h>
#define maxn 4000

using namespace std;


deque < pair <int, int> > q;
int n, a[maxn], p[maxn], ans = 0, dd[maxn], c = 0, k;
int m[maxn][maxn];

void dfs(int c, int x, int y)
{
    if (m[x][y])
        return;
    m[x][y] = 1;
    ans ++;
    if (c == 0 || y > n)
        return;
    if (a[x] && p[y])
        dfs(c-1, y+1, y+2);
    if (a[x] && p[y] != 100)
        dfs(c-1, x, y+1);
    if (a[x]!=100 && p[y]>0)
        dfs(c-1, y, y+1);
    return;
}

int main()
{
    memset(dd, 0, sizeof(dd));
    memset(m, 0, sizeof(m));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1)
        return cout << 1, 0;
    p[n] = a[n];
    for (int i = n-1; i >= 1; i--)
        p[i] = max(p[i+1], a[i]);
    dfs(k, 1, 2);
    cout << ans+c;
    return 0;
}
