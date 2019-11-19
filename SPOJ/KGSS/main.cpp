#include <bits/stdc++.h>
#define maxn 100005

using namespace std;


struct pii {
    int m1;
    int m2;
    pii (){};
    pii (int _x, int _y)
    {
        m1 = _x;
        m2 = _y;
    }
};
 pii tree[4*maxn];
 int a[maxn];
 int n, q;

void update (int node, int l, int r, int i, int x)
{
    if (l > i || r < i)
        return;
    if (l == i && l == r)
    {
        tree[node].m1 = x;
        return;
    }
    int m = (l+r) >> 1;

    update (2*node, l, m, i, x);
    update (2*node+1, m+1, r, i, x);

    int m1 = tree[2*node].m1;
    int m2 = tree[2*node].m2;
    int m3 = tree[2*node+1].m1;
    int m4 = tree[2*node+1].m2;

    if (m1 < m3)
    {
        tree[node].m1 = m3;
        tree[node].m2 = max(m2, max(m1, m4));
        return;
    }
    tree[node].m1 = m1;
    tree[node].m2 = max(m2, max(m3, m4));
    return;
}

void init (int node, int l, int r)
{
    if (l == r)
    {
        tree[node].m1 = a[l];
        tree[node].m2 = INT_MIN;
        return;
    }

    int m = (l+r)>>1;

    init (2*node, l, m);
    init (2*node+1, m+1, r);

    int m1 = tree[2*node].m1;
    int m2 = tree[2*node].m2;
    int m3 = tree[2*node+1].m1;
    int m4 = tree[2*node+1].m2;

    if (m1 < m3)
    {
        tree[node].m1 = m3;
        tree[node].m2 = max(m2, max(m1, m4));
        return;
    }
    tree[node].m1 = m1;
    tree[node].m2 = max(m2, max(m3, m4));
}

pii get (int node, int l, int r, int u, int v)
{
    if (l > v || r < u)
        return {INT_MIN, INT_MIN};
    if (u <= l && r <= v)
        return tree[node];
    int m = (l+r) >> 1;
    pii res1 = get (2*node, l, m, u, v), res2 = get (2*node+1, m+1, r, u, v);
    if (res1.m1 > res2.m1)
        return {res1.m1, max(res1.m2, max(res2.m1, res2.m2))};
    else
        return {res2.m1, max(res2.m2, max(res1.m1, res1.m2))};
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init(1, 1, n);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        char u;
        int x, y;
        cin >> u >> x >> y;
        if (u == 'U')
        {
            update (1, 1, n, x, y);
            continue;
        }
        pii res = get (1, 1, n, x, y);
        cout << res.m1 + res.m2 << endl;
    }
    return 0;
}
