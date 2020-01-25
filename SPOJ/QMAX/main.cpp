#include <bits/stdc++.h>
#define maxn 101

using namespace std;

int n, m;
int tree[4*maxn], f[4*maxn];

void down(int node)
{
    tree[2*node] += f[node];
    tree[2*node+1] += f[node];
    f[2*node] += f[node];
    f[2*node+1] += f[node];
    f[node] = 0;
    return;
}
void update(int node, int l, int r, int u, int v, int w)
{
    if (l > v || r < u)
        return;
    if (u <= l && r <= v)
    {
       tree[node] += w;
       f[node] += w;
       return;
    }
    down(node);
    int g = (l+r) >> 1;
    update(2*node, l, g, u, v, w);
    update(2*node+1, g+1, r, u, v, w);
    tree[node] = max(tree[2*node], tree[2*node+1]);
    return;
}

int get(int node, int l, int r, int u, int v)
{
    if (l > v || r <u)
        return INT_MIN;
    if (u <= l && r <= v)
        return tree[node];
    down(node);
    int g = (l+r)>>1;
    int q1 = get(2*node, l, g, u, v);
    int q2 = get(2*node+1, g+1, r, u, v);
    return max(q1, q2);
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= m; i++)
    {
        int u, v, k;
        cin >> u >> v >> k;
        update (1, 1, n, u, v, k);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << get(1, 1, n, u, v) << endl;
    }
    return 0;
}
