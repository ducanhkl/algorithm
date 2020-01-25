#include <bits/stdc++.h>
#define maxn 500051

using namespace std;



long long tree[4*maxn], f[4*maxn], t[maxn], p[maxn], dd[maxn];
int n;

void push(int cha, int con)
{
    f[con] = min(f[con], f[cha]);
    tree[con] = min(tree[con], f[cha]);
    return;
}
void init(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = dd[l];
        return;
    }
    int g = (l+r)/2;
    init(2*node, l, g);
    init(2*node+1, g+1, r);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

void update (int node, int l, int r, int u, int v, long long w)
{
    if (l > v || r < u)
        return;
    push(node, 2*node);
    push(node, 2*node+1);
    f[node] = INT_MAX;
    if (l >= u && r <= v)
    {
        tree[node] = min(tree[node], w);
        f[node] = min(f[node], w);
        return;
    }
    int g = (l+r) >> 1;
    update(2*node, l, g, u, v, w);
    update(2*node+1, g+1, r, u, v, w);
    tree[node] = min(tree[2*node], tree[2*node+1]);
    return;
}

long long get(int node, int l, int r, int u, int v)
{
    if (l > v || r < u)
        return INT_MAX;
    push(node, 2*node);
    push(node, 2*node+1);
    f[node] = INT_MAX;
    if (l >= u && r <= v)
        return tree[node];
    int g = (l+r)>>1;
    return min(get(2*node, l, g, u, v), get(2*node+1, g+1, r, u, v));
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];
    for (int i = 0; i <= n; i++)
        dd[i] = INT_MAX;
    for (int i = 0; i < 4*maxn; i++)
        f[i] = INT_MAX;
    dd[0] = 0;
    init(1, 0, n);
    for (int i = 1; i <= n; i++)
    {
        int res = get(1, 0, n, i-1, i-1);
        update (1, 0, n, i, t[i], res+p[i]);
    }
    cout << get(1, 0, n, n, n);
    return 0;
}
