#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;
const long long maxc = 1e18+100;

int n;
long long a[maxn], t[maxn], st[maxn], b[maxn], k[maxn];
long long tree[8*maxn], f[8*maxn];


void init(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = b[l];
        return ;
    }
    int mid = (l+r)>>1;
    init(2*node, l, mid);
    init(2*node+1, mid+1, r);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void down(int node_par, int node_child, int l, int r)
{
    tree[node_child] = f[node_par]*(r-l+1);
    f[node_child] = f[node_par];
}

long long get(int node, int l, int r, int u, int v)
{
    int mid = (l+r)>>1;
    if (f[node] != -maxc)
    {
        down(node, 2*node, l, mid);
        down(node,  2*node+1, mid+1, r);
        f[node] = -maxc;
    }
    if (l >= u && r <= v)
        return tree[node];
    if (l > v || r < u)
        return 0;
    long long res1 = get(2*node, l, mid, u, v);
    long long res2 = get(2*node+1, mid+1, r, u, v);
    return res1+res2;
}

void update(int node, int l, int r, int u, int v, long long val)
{
    int mid = (l+r)>>1;
    if (f[node] != -maxc)
    {
        down(node, 2*node, l, mid);
        down(node,  2*node+1, mid+1, r);
        f[node] = -maxc;
    }
    if (l >= u && r <= v)
    {
        f[node] = val;
        tree[node] = val*(r-l+1);
        return ;
    }
    if (l > v || r < u)
        return ;
    update(2*node, l, mid, u, v, val);
    update(2*node+1, mid+1, r, u, v, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(f, 0, sizeof(f));
    memset(tree, 0, sizeof(tree));
    memset(k, 0, sizeof(k));
    memset(t, 0, sizeof(t));
    memset(st, 0, sizeof(st));
    for (int i = 0; i < 4*maxn; i++)
        f[i] = -maxc;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        cin >> k[i];
    for (int i = 1; i <= n; i++)
        t[i] = t[i-1]+k[i-1];
    for (int i = 1; i <= n; i++)
        st[i] = st[i-1] + t[i];
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - t[i];
    init(1, 1, n);
    int q;
    cin >> q;
    int test = 0;
    while(q--)
    {
        test++;
        char s;
        cin >> s;
        if (s == 's')
        {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r)+st[r]-st[l-1] << endl;
            continue;
        }
        int pos;
        long long x;
        cin >> pos >> x;
        long long val = get(1, 1, n, pos, pos)+x;
        int l = pos, r = n, ans = pos;
        while (l <= r)
        {
            int mid = (l+r)/2;
            long long res = get(1, 1, n, mid, mid);
            if (res > val)
                r = mid-1;
            else
                ans = mid, l = mid+1;
        }
        update(1, 1, n, pos, ans, val);
    }
    return 0;
}
