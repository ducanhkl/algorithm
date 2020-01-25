#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
int n, m, q;
int p[maxn], a[maxn], pre[maxn], ans[maxn], last[maxn];
int spt[maxn][30];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    p[0] = p[n];
    for (int i = 1; i <= n; i++)
        pre[p[i]] = p[i-1];
    for (int i = 1; i <= m; i++)
    {
        spt[i][0] = last[pre[a[i]]];
        for (int k = 1; k <= 20; k++)
            spt[i][k] = spt[spt[i][k-1]][k-1];
        last[a[i]] = i;
        int pos = i;
        for (int k = 0; k <= 20; k++)
            if (((n-1) >> k) & 1)
                pos = spt[pos][k];
        ans[i] = max(ans[i-1], pos);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (ans[r] >= l)
            cout << 1;
        else
            cout << 0;
    }
    return 0;
}
