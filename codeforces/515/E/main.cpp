#include <bits/stdc++.h>

using namespace std;


struct data
{
    long long l, r, ma;
};

const int maxn = 5e5+100;

int n, m;
long long h[maxn], d[maxn];
data tree[maxn];

data up(data node1, data node2)
{
    data res;
    res.l = max(node1.l, node2.l);
    res.r = max(node1.r, node2.r);
    res.ma = max(node1.l + node2.r, max(node1.ma, node2.ma));
    return res;
}

void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node].ma = 0;
        tree[node].l = 2*h[l] - d[l-1];
        tree[node].r = 2*h[l] + d[l-1];
        return ;
    }
    int mid = (l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node] = up(tree[2*node], tree[2*node+1]);
    return ;
}

data get(int node, int l, int r, int u, int v)
{
    if (u <= l && r <= v)
    {
        return tree[node];
    }
    int mid = (l+r) >>  1;
    if (u > mid)
        return get(2*node+1, mid+1, r, u, v);
    if (v <= mid)
        return get(2*node, l, mid, u, v);
    data res1 = get(2*node, l, mid, u, v);
    data res2 = get(2*node+1, mid+1, r, u, v);
    return up(res1, res2);
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        d[i+n] = d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        h[i+n] = h[i];
    }
    n *= 2;
    for (int i = 1; i <= n; i++)
    {
        d[i] += d[i-1];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        data res;
        if (a <= b)
        {
            res = get(1, 1, n, b+1, a+n/2-1);
        }
        else
        {
            swap(a, b);
            res = get(1, 1, n, a+1, b-1);
        }
        cout << res.ma << endl;
    }
}
