#include <bits/stdc++.h>
#define reset(a) memset(a, 0, sizeof(a))
#define maxn 100009

using namespace std;

int in[maxn], t[maxn],  treelca[4*maxn], tree1[4*maxn], tree2[4*maxn], par[maxn][30], h[maxn];
int n, q, tt = 0;
vector <int> e[maxn];

void dfs(int u)
{
    in[u] = ++tt;
    t[tt] = u;
    for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i];
            h[v] = h[u]+1;
            par[v][0] = u;
            dfs(v);
        }
}

void rmq()
{
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++)
            par[j][i] = par[par[j][i-1]][i-1];
}

int getpar(int u, int len)
{
    for (int i = 20 ; i >= 0; i --)
        if ((len>>i)&1)
            u = par[u][i];
    return u;
}

int lca(int u, int v)
{
    if (u == 0)
        return v;
    if (v == 0)
        return u;
    if (h[v] < h[u])
        swap(u, v);
    int d = h[v] - h[u];
    v = getpar(v, d);
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
        if (par[u][i] != par[v][i])
    {
        u = par[u][i];
        v = par[v][i];
    }
    return par[v][0];
}

void buildlca(int node, int l, int r)
{
    if (l == r)
    {
        treelca[node] = l;
        return ;
    }
    int mid = (l+r)>>1;
    buildlca(2*node, l, mid);
    buildlca(2*node+1, mid+1, r);
    treelca[node] = lca(treelca[2*node], treelca[2*node+1]);
    return ;
}

int getlca(int node, int l, int r, int u, int v)
{
    if (u > v)
        return 0;
    if (u > r || v < l)
        return 0;
    if (u <= l && v >= r)
    {
        return treelca[node];
    }
    node *= 2;
    int mid = (l+r)>>1;
    int u1 = getlca(node, l, mid, u, v);
    int v1 = getlca(node+1, mid+1, r, u, v);
    return lca(u1, v1);
}

// begin of min and max using inteval tree

void buildtree(int node, int l, int r)
{
    if (l==r)
    {
        tree1[node] = in[l];
        tree2[node] = in[l];
        return;
    }
    int mid = (l+r) >> 1;
    buildtree(2*node, l, mid);
    buildtree(2*node+1, mid+1, r);
    tree1[node] = max(tree1[2*node], tree1[2*node+1]);
    tree2[node] = min(tree2[2*node], tree2[2*node+1]);
    return ;
}

int getmin(int node, int l, int r, int u, int v)
{
    if (u > r || v < l)
        return  INT_MAX;
    if (u <= l && v >= r)
        return tree2[node];
    int mid = (l+r)>>1;
    node *= 2;
    return min(getmin(node, l, mid, u, v), getmin(node+1,mid+1, r, u, v));
}

int getmax(int node, int l, int r, int u, int v)
{
    if (u > r || v < l)
        return  INT_MIN;
    if (u <= l && v >= r)
        return tree1[node];
    int mid = (l+r)>>1;
    node *= 2;
    return max(getmax(node, l, mid, u, v), getmax(node+1,mid+1, r, u, v));
}

// end

int getv(int l, int r, int mid)
{
    int u1 = getlca(1, 1, n, l, mid-1);
    int v1 =  getlca(1, 1, n, mid+1, r);
    return lca(u1, v1);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    reset(tree1), reset(tree2), reset(treelca), reset(par);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 2; i  <= n; i++)
    {
        int x;
        cin >> x;
        e[x].push_back(i);
    }
    h[1] = 0;
    dfs(1);
    par[1][0] = 1;
    rmq();
    buildlca(1, 1, n);
    buildtree(1, 1, n);
    //cout << lca(10, 11) << endl;
    //cout << getlca(1, 1, n, 9, 11) << endl;
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        int lef = t[getmin(1, 1, n, u, v)];
        int rig = t[getmax(1, 1, n, u, v)];
        int v1 = getv(u, v, lef);
        int v2 = getv(u, v, rig);
        if (h[v1] < h[v2])
            cout << rig << " " << h[v2] << endl;
        else
            cout << lef << " " << h[v1] << endl;
    }
}
