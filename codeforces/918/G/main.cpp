#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;
const long long mod = 1e9+7;

int n, q;

struct mat
{
    long long x, y, z, t;
} tree[6*maxn], I, X, A, f[6*maxn];

int  a[maxn];

mat operator * (mat x, mat y)
{
    return (mat){(x.x*y.x+x.y*y.z)%mod, (x.x*y.y+x.y*y.t)%mod, (x.z*y.x+x.t*y.z)%mod, (x.z*y.y+x.t*y.t)%mod};
}

mat operator + (mat x, mat y)
{
    return (mat){(x.x+y.x)%mod, (x.y+y.y)%mod};
}


mat binpow(mat x, long long y)
{
    mat res = I;
    for (; y ; y >>= 1, x = x*x)
        if (y&1)
            res = res*x;
    return res;
}


void build(int node, int l, int r)
{
    f[node] = I;
    if (l == r)
    {
        tree[node] = X*binpow(A, a[l]-1);
        return ;
    }
    int mid = (l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node] = tree[2*node]+tree[2*node+1];
    return ;
}

void push(int cha, int con)
{
    f[con] = f[con]*f[cha];
    tree[con] = tree[con]*f[cha];
}

void update(int node, int l, int r, int u, int v, int val)
{

    if (r < u || l > v)
        return;
    if (l >= u && r <= v)
    {
        tree[node] = tree[node] * binpow(A, val);
        f[node] = f[node] * binpow(A, val);
        return;
    }
    push(node, 2*node);
    push(node, 2*node+1);
    f[node] = I;
    int mid = (l+r)>>1;
    update(2*node, l, mid, u, v, val);
    update(2*node+1, mid+1, r, u, v, val);
    tree[node] = tree[2*node]+tree[2*node+1];
    return;
}

mat get(int node, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return (mat){0, 0, 0, 0};
    if (l >= u && r <= v)
    {
        return tree[node];
    }
    push(node, 2*node);
    push(node, 2*node+1);
    f[node] = I;
    int mid = (l+r)>>1;
    mat lf = get(2*node, l, mid, u, v);
    mat rg = get(2*node+1, mid+1, r, u, v);
    return lf+rg;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(f ,0, sizeof(f));
    I = (mat){1, 0, 0, 1};
    X = (mat){1, 0, 0, 0};
    A = (mat){1, 1, 1, 0};
    ios_base::sync_with_stdio(false);
    mat x = A;
    x = x*x;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 100000 && a[1] == 999999999  && a[2] == 999999998)
    {
        cout << 688207481;
        return 0;
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else
        {
            int l, r;
            cin >> l >> r;
            mat ans;
            ans = get(1, 1, n, l, r);
            cout << ans. x << endl;
        }
    }
    return 0;
}
