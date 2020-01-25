#include <bits/stdc++.h>
#define maxn 200005

using namespace std;

long long n, x, y;
long long ans = 0, cnt[maxn];
vector <int> e[maxn];

int dfs(int u, int par = 0)
{
    int l = 2;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        if (dfs(v, u) && l)
            ans ++, l --;
    }
    return l;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        cnt[u]++, cnt[v]++;
    }
    if (x<=y)
    {
        dfs(1);
        cout << ans*x + (n-ans-1)*y;
    }else
    {
        int ck = 0;
        for (int i = 1; i <= n; i++)
            if (cnt[i] == n-1)
                ck = 1;
        cout << y*(n-1-ck) + x*ck;
    }
    return 0;
}
