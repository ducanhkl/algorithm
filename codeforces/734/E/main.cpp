#include <bits/stdc++.h>
#define maxn 200005

using namespace std;

int dis[maxn],c[maxn], color[maxn], cnt = 0, n, g = 0;
vector <int> e1[maxn];
vector <int> e2[maxn];

void dfs(int u, int par = 0)
{
    c[u] = cnt;
    for (int i = 0; i < e1[u].size(); i++)
    {
        int v = e1[u][i];
        if (v == par)
            continue;
        if (color[v] != color[u])
            continue;
        dfs(v, u);
    }
}

int dfs1(int u, int par = 0)
{
    for (int i = 0; i < e2[u].size(); i++)
    {
        int v = e2[u][i];
        if (v == par || dis[v] != 0)
            continue;
        dis[v] = dis[u]+1;
        dfs1(v, u);
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e1[u].push_back(v);
        e1[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!c[i])
    {
        cnt ++;
        dfs(i);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < e1[i].size(); j++)
    {
        int v = e1[i][j];
        if (c[i] != c[v])
        {
            e2[c[i]].push_back(c[v]);
            e2[c[v]].push_back(c[i]);
        }
    }
    /*for (int i = 1; i <= cnt; i++)
    {
        cout << i << " ";
        for (int j = 0; j < e2[i].size(); j++)
            cout << e2[i][j] << " ";
        cout << endl;
    }*/
    memset(dis, 0, sizeof(dis));
    dfs1(1);
    for (int i = 1; i <= n; i++)
        if (g == 0 || dis[i] > dis[g])
            g = i;
    memset(dis, 0, sizeof(dis));
    dfs1(g);
    g = 0;
    for (int i = 1; i <= n; i++)
        if (g == 0 || dis[i] > dis[g])
            g = i;
    cout << (dis[g]+1)/2;
    return 0;
}
