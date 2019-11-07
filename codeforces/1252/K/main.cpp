#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;
const long long mod = 1e9+7;

struct data
{
    long long x, y, z, t;
    void reset()
    {
        x = t = 1;
        y = z = 0;
    }
    void dmod()
    {
        x %= mod;
        y %= mod;
        z %= mod;
        t %= mod;
    }
};



data tree[4*maxn + 100];
int n, q, f[4*maxn + 100];
char c[maxn];


data mul(data x, data y)
{
    data res;
    res.reset();
    res.x = x.x*y.x%mod+x.y*y.z%mod;
    res.y = x.x*y.y%mod+x.y*y.t%mod;
    res.z = x.z*y.x%mod+x.t*y.z%mod;
    res.t = x.z*y.y%mod+x.t*y.t%mod;
    res.dmod();
    return res;
}


void push(int node)
{
    if (f[node] == 0)
        return ;
    swap(tree[node].x, tree[node].t);
    swap(tree[node].y, tree[node].z);
    f[2*node] ^= 1;
    f[2*node+1] ^= 1;
    f[node] = 0;
    return ;
}

void up(int node)
{
    tree[node] = mul(tree[2*node], tree[2*node+1]);
    return ;
}


void init(int node, int l, int r)
{
    if (l == r)
    {
        if (c[l] == 'A')
            tree[node] = {1, 0, 1, 1};
        else
            tree[node] = {1, 1, 0, 1};
        return ;
    }
    int mid = (l+r) >> 1;
    init(2*node, l, mid);
    init(2*node+1, mid+1, r);
    up(node);
}


void update(int node, int l, int r, int u, int v)
{
    push(node);
    if (l > v || r < u)
    {
        return ;
    }
    if (u <= l && r <= v)
    {
        f[node] ^= 1;
        push(node);
        return ;
    }
    int mid = (l+r)>>1;
    update(2*node, l, mid, u, v);
    update(2*node+1, mid+1, r, u, v);
    up(node);
}

data get(int node, int l, int r, int u, int v)
{
    push(node);
    data res;
    res.reset();
    if (l > v || r < u)
        return res;
    if (u <= l && r <= v)
    {
        return tree[node];
    }
    int mid = (l+r)>>1;
    data res1 = get(2*node, l, mid, u, v);
    data res2 = get(2*node+1, mid+1, r, u, v);
    res = mul(res1, res2);
    return res;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    init(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        int t;
        long long l, r, a, b;
        cin >> t;
        if (t == 1)
        {
            cin >>l >> r;
            update(1, 1, n, l, r);
        }
        if (t == 2)
        {
            cin >> l >>r >> a >> b;
            data no = get(1, 1, n, l, r);
            long long aa = no.x*a%mod + no.z*b%mod;
            aa %= mod;
            long long bb = no.y*a%mod + no.t*b%mod;
            bb %= mod;
            cout << aa << " " << bb << endl;
        }
    }
    return 0;
}
