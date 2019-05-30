#include <bits/stdc++.h>
#define maxn 1000007

using namespace std;

struct data
{
    int logic, u, v;
    bool tt;
    node () {};
};

data node[maxn];
int n;
bool dd[maxn];
string logic[maxn];

int dfs(int u)
{
    if (node[u].logic == 5)
        return node[u].tt;
    if (node[u].logic == 4)
    {
        node[u].tt = !dfs(node[u].u);
    }
    if (node[u].logic == 3)
    {
        node[u].tt = (dfs(node[u].u)^dfs(node[u].v));
    }
    if (node[u].logic == 2)
    {
        node[u].tt = (dfs(node[u].u)|dfs(node[u].v));
    }
    if (node[u].logic == 1)
    {
        node[u].tt = (dfs(node[u].u)&dfs(node[u].v));
    }
    return node[u].tt;
}

int dfs1(int u)
{
    if (node[u].logic == 5)
        dd[u] = 1;
    if (node[u].logic == 4)
        dfs1(node[u].u);
    if (node[u].logic == 3)
    {
        dfs1(node[u].u);
        dfs1(node[u].v);
    }
    if (node[u].logic == 2)
    {
        if (node[node[u].u].tt == 0)
            dfs1(node[u].v);
        if (node[node[u].v].tt == 0)
            dfs1(node[u].u);
    }
    if (node[u].logic == 1)
    {
        if (node[node[u].u].tt)
            dfs1(node[u].v);
        if (node[node[u].v].tt)
            dfs1(node[u].u);
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> logic[i];
        if (logic[i] == "AND")
            {
                node[i].logic = 1;
                cin >> u >> v;
                node[i].u = u;
                node[i].v = v;
            }
        if (logic[i] == "OR")
            {
                node[i].logic = 2;
                cin >> u >> v;
                node[i].u = u;
                node[i].v = v;
            }
        if (logic[i] == "XOR")
            {
                node[i].logic = 3;
                cin >> u >> v;
                node[i].u = u;
                node[i].v = v;
            }
        if (logic[i] == "NOT")
            {
                node[i].logic = 4;
                cin >> u;
                node[i].u = u;
            }
        if (logic[i] == "IN")
            {
                node[i].logic = 5;
                cin >> u;
                node[i].tt = u;
            }

    }
    dfs(1);
    memset(dd, 0, sizeof(dd));
    dfs1(1);
    for (int i = 1; i <= n; i++)
        if (logic[i] == "IN")
            cout << (dd[i]^node[1].tt);
    return 0;
}
