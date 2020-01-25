#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
vector <int> m[maxn];
int n, ans, res = 0;
int a[maxn], dd[maxn], ufr[maxn];
vector <int> e[maxn];

int dfs(int u, int par)
{
    ufr[u] = 1;
    int mx1 = 0, mx2 = 0;
    for (int i = 0;  i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par || dd[v] == 0)
            continue;
        int tt = dfs(v, u);
        mx2 = max(mx2, tt);
        if (mx2 > mx1)
            swap(mx2, mx1);
    }
    ans = max(max(ans, max(mx1, mx2)+1), mx2+mx1+1);
    return max(mx1, mx2)+1;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= sqrt(a[i]); j++)
            if (a[i]%j == 0)
        {
            m[j].push_back(i);
            while (a[i]%j == 0)
                a[i] /= j;
        }
        if (a[i] != 1)
            m[a[i]].push_back(i);
    }
    for (int i = 0; i < maxn; i++)
        if (m[i].size() != 0)
    {
        ans = 0;
        memset(dd, 0, sizeof(dd));
        memset(ufr, 0, sizeof(ufr));
        for (int j = 0; j < m[i].size(); j++)
            dd[m[i][j]] = 1;
        for (int i = 1; i <= n; i++)
            if (dd[i] == 1 && ufr[i] == 0)
                dfs(i, i);
        res = max(ans, res);
    }
    cout << res;
    return 0;
}
