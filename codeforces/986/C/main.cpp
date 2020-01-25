#include <bits/stdc++.h>
#define maxm 5000006

using namespace std;

bool dd[maxm], mark[maxm];
int a[maxm];
int full, n, m, ans = 0;

int dfs (int  u)
{
    if (mark[u])
        return 0;
    mark[u] = true;
    if (dd[u])
        dfs(full - u);
    for (int i = 0; i < n; i++)
        if (u & (1 << i))
            dfs(u^(1<<i));
    return 0;
}
int main()
{
    memset(dd, 0, sizeof(dd));
    memset(mark, 0, sizeof(mark));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    full = (1 << n)-1;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        dd[a[i]] = true;
    }
    for (int i = 1; i <= m; i++)
        if (!mark[a[i]])
            ans ++, dfs(full - a[i]);
    cout << ans;
    return 0;
}
