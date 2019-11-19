#include <bits/stdc++.h>
#define maxn 100000

using namespace std;

int dd[maxn], d[maxn], n, c;
vector <int> e[maxn];

int dfs(int u)
{
    dd[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (dd[v] == 0)
        {
            d[v] = d[u] + 1;
            dfs(v);
        }
    }
    return 0;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> c;
    for (int i = 1; i <= c; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back(v);
        e[u].push_back(w);
    }
    memset(dd, 0, sizeof(dd));
    memset(d, 0, sizeof(d));
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << d[i] + 1 << endl;
    return 0;
}
