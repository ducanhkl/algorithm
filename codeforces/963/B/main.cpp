#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int d[maxn], n, root;
vector <int> e[maxn];

void dfs1(int u)
{
    d[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        dfs1(v);
        d[u] += d[v];
    }
    return;
}

void dfs2(int u)
{
    for (int i = 0; i < e[u].size(); i++)
        if (d[e[u][i]] % 2 == 0)
            dfs2(e[u][i]);
    cout << u << endl;
    for (int i = 0; i < e[u].size(); i++)
        if (d[e[u][i]]%2)
            dfs2(e[u][i]);
    return;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n%2 == 0)
        return cout << "NO", 0;
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
            root = i;
        else e[x].push_back(i);
    }
    dfs1(root);
    dfs2(root);
    return 0;
}
