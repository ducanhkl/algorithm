#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

int n, m, q, color = 0;
long long dp[maxn][3];
int col[maxn];
map < pair<int, int>, long double > res;
vector <int> e[maxn];
vector <long long> sl[maxn], sm[maxn];

int dfs1(int u, int par = 0)
{
    col[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (col[v])
            continue;
        dfs1(v, u);
        if (dp[u][0] < dp[v][0] + 1)
            dp[u][1] = dp[u][0],
            dp[u][0] = dp[v][0] + 1;
        else
            if (dp[u][1] < dp[v][0]+1)
                dp[u][1] = dp[v][0] + 1;
    }
}

int dfs2(int u, long long dem)
{
    col[u] = color;
    sl[color].push_back(max(dem, dp[u][0]));
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (col[v])
            continue;
        if (dp[u][0] == dp[v][0]+1)
            dfs2(v, max(dem, dp[v][1])+1);
        else dfs2(v, max(dem, dp[v][0])+1);
    }
}

int solve(int x, int y)
{
    if (col[x] == col[y])
        return cout << -1 << endl, 0;
    x = col[x];
    y = col[y];
    if (sl[x].size() < sl[y].size())
        swap(x, y);
    int len1 = sl[x].size(), len2 = sl[y].size();
    if (res[(pair <int, int>) {x, y}])
        return cout << res[(pair <int, int>) {x, y}] << endl, 0;
    long long mm = max(*sl[x].rbegin(), *sl[y].rbegin());
    long long ans = 0;
    for (int i = 0; i < sl[y].size(); i++)
    {
        long long z = sl[y][i];
        long long pos = upper_bound(sl[x].begin(), sl[x].end(), mm-z-1)-sl[x].begin();
        ans += (z+1)*(len1-pos) + mm*pos;
        ans += sm[x][len1] - sm[x][pos];
    }
    res[(pair <int, int>) {x, y}] = 1.0*ans/len1/len2;
    cout << fixed << setprecision(10) << 1.0*ans/len1/len2 << endl;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!col[i])
            dfs1(i);
    memset(col, 0, sizeof(col));
    for (int i = 1; i <= n; i++)
        if (!col[i])
    {
        color ++;
        dfs2(i, 0);
        sort(sl[color].begin(), sl[color].end());
        sm[color].push_back(0);
        for (int i = 0; i < sl[color].size(); i++)
            sm[color].push_back(*sm[color].rbegin() + sl[color][i]);
    }
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        solve(u, v);
    }
    return 0;
}
