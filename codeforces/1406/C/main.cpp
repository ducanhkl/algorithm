#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;

int sz[maxn];
vector <int> e[maxn];
int v1 = 0, v2 = 0, v3 = 0;
int n;

void dfs(int u, int par)
{
    sz[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    if (e[u].size() == 1 && v3 == 0 && par != 0)
    {
        v1 = par;
        v2 = u;
    } else
    {
        if (n-sz[u] == sz[u])
        {
            v3 = par;
        }
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        v1 = v2 = v3 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            e[i].resize(0),
            sz[i] = 0;
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        dfs(1, 0);
        cout << v1 << " " << v2 << endl;
        cout << v2 << " " << (v3?v3:v1) << endl;
    }
    return 0;
}
