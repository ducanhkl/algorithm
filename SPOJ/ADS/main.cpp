#include <bits/stdc++.h>
#define maxn 100004

using namespace std;

int dd[maxn], n, m, tp = 0;
vector <int> e[maxn];

void dfs(int u)
{
    dd[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
        if (dd[e[u][i]] == 0)
            dfs(e[u][i]);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (dd[i] == 0)
            tp++, dfs(i);
    cout << m-n+tp;
    return 0;
}
