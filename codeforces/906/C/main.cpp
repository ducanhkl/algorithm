#include <bits/stdc++.h>

using namespace std;

int n, m;
int p[100], dp[1<<23];
int trace[1<<23], tr[1<<23], ans[100], dem = 0;

int main()
{
    memset(trace, 0, sizeof(trace));
    memset(tr, 0, sizeof(tr));
    freopen("inp.txt", "r", stdin);
    memset(p, 0, sizeof(p));
    memset(dp, 0,  sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        p[i] = 1<<i;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        p[u] |= (1<<v);
        p[v] |= (1<<u);
    }
    for (int i = 1; i < 1<<n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
            if ((i>>j)&1 && ((i&p[j]) != i))
                break;
        if (j < n)
            dp[i] = 1000;
        else
            dp[i] = 0;
    }
    for (int i = 1; i < 1<<n; i++)
        for (int j = 0; j < n; j++)
            if ((i>>j)&1 && dp[i|p[j]] > dp[i]+1)
                {
                    dp[i|p[j]] = dp[i]+1;
                    trace[i|p[j]] = i;
                    tr[i|p[j]] = j;
                }
    cout << dp[(1<<n)-1] << endl;
    int root = (1<<n)-1;
    while (root != 0)
    {
        ans[++dem] = tr[root];
        root = trace[root];
    }
    for (int i = 1; i < dem; i++)
        cout << ans[i]+1 << " ";
    return 0;
}
