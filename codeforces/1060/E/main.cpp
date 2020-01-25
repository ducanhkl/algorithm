#include <bits/stdc++.h>
#define maxn 2000006

using namespace std;

int n;
vector <int> e[maxn];
long long cnt[maxn], ans, dd[maxn];

void dfs(int u, int par, int p)
{
    cnt[u] = 1;
    dd[p] ++;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs(v, u, (p+1)%2);
        cnt[u] += cnt[v];
    }
    ans += cnt[u]*(n-cnt[u]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
    dfs(1, 0, 0);
    ans += dd[0]*dd[1];
    ans /= 2;
    cout << ans;
    return 0;
}
