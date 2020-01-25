#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
int dd[maxn], c[maxn];
vector <int> e[maxn];

void dfs(int u, int par = 0)
{
    dd[u] = c[u];
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs(v, u);
        dd[u] = dd[u]&c[v];
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int root;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, x;
        cin >> u >> x;
        if (u == -1)
        {
            c[i] = x;
            root = i;
            continue;
        }
        e[i].push_back(u);
        e[u].push_back(i);
        c[i] = x;
    }
    dfs(root);
    int check = 0;
    for (int i = 1; i <= n; i++)
        if (dd[i])
            {
                check = 1;
                cout << i << " ";
            }
    if (check == 0)
        cout << -1;
    return 0;
}
