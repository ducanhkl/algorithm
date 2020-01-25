#include <bits/stdc++.h>
#define maxn 110

using namespace std;

int e[maxn+10][maxn+10], sl[maxn+10], fr[maxn+10];
int ans = 0, k, l, n, m, t;

int dis(int u)
{
    ans += u;
    fr[u] = 1;
    n--;
    for (int i = 1; i <= maxn; i++)
        if (e[u][i])
    {
        e[u][i] = 0, e[i][u] = 0;
        sl[u] --, sl[i] --;
        if (!fr[i] && sl[i] < k)
            dis(i);
    }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    int c = 0;
    while (t--)
    {
        memset(e, 0, sizeof(e));
        memset(sl, 0, sizeof(sl));
        memset(fr, 0, sizeof(fr));
        ans = 0;
        cin >> k >> l >> n >> m;
        int _n = n;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u][v] = e[v][u] = 1;
            sl[u] ++, sl[v] ++;
        }
        for (int i = 1; i <= _n; i++)
            if (!fr[i] && sl[i] < k)
                dis(i);
        for (int i = 1; i <= _n; i++)
            if (!fr[i] && n - sl[i] - 1 < l)
                dis(i), i = 1;
        cout << "Case #" << ++c << endl;
        cout << ans << endl;
    }
    return 0;
}

