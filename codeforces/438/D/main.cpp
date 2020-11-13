#include <bits/stdc++.h>

using namespace std;


const long long maxn = 1e5+100;

long long seg_tree[4*maxn], maxx[4*maxn];
long long a[maxn];
long long n, m;

void push_up(long long node)
{
    seg_tree[node] = seg_tree[2*node] + seg_tree[2*node+1];
    maxx[node] = max(maxx[2*node], maxx[2*node+1]);
}

void build(long long node, long long l, long long r)
{
    if (l == r)
    {
        seg_tree[node] = a[l];
        maxx[node] = a[l];
        return ;
    }
    long long mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    push_up(node);
}

void update_mod(long long node, long long l, long long r, long long u, long long v, long long val)
{
    if (l > v || r < u || maxx[node] < val)
    {
        return ;
    }
    if (l == r)
    {
        seg_tree[node] %= val;
        maxx[node] = seg_tree[node];
        return ;
    }
    long long mid = (l+r)/2;
    update_mod(2*node, l, mid, u, v, val);
    update_mod(2*node+1, mid+1, r, u , v , val);
    push_up(node);
}

void update(long long node, long long l, long long r, long long u, long long v, long long val)
{
    if (l > v || r < u)
    {
        return ;
    }
    if (u <= l && r <= v)
    {
        seg_tree[node] = val;
        maxx[node] = seg_tree[node];
        return ;
    }
    long long mid = (l+r)/2;
    update(2*node, l, mid, u, v, val);
    update(2*node+1, mid+1, r, u , v , val);
    push_up(node);
}

long long get(long long node, long long l, long long r, long long u, long long v)
{
    if (l > v || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return seg_tree[node];
    }
    long long mid = (l+r)/2;
    long long res1 = get(2*node, l, mid, u, v);
    long long res2 = get(2*node+1, mid+1, r, u , v);
    return res1+res2;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    for (long long i = 1; i <= m; i++)
    {
        long long c, x, y, mod;
        cin >> c >> x >> y;
        if (c == 1)
        {
            long long res = get(1, 1, n, x, y);
            cout << res << endl;
        }
        if (c == 2)
        {
            cin >> mod;
            update_mod(1, 1, n, x, y, mod);
        }
        if (c == 3)
        {
            update(1, 1, n, x, x, y);
        }
    }
    return 0;
}
