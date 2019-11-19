#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e6;

int q;
int a[maxn], b[maxn];
long long ans = 0;

struct data
{
    long long sum;
    long long ti;
} tree[5*maxn];



void update(int node)
{
    tree[node].sum = tree[node*2].sum + tree[2*node+1].sum;
    tree[node].ti = max(tree[2*node].ti + tree[2*node+1].sum, tree[2*node+1].ti);
    return ;
}

void init(int node = 1, int l = 1, int r = maxn)
{
    if (l == r)
    {
        tree[node].ti = l;
        return ;
    }
    int mid = (l+r)>>1;
    init(2*node, l, mid);
    init(2*node+1, mid+1, r);
    update(node);
}

void update(int node, int l, int r, int u, int val)
{
    if (l == r)
    {
        tree[node].ti += val;
        tree[node].sum += val;
        return ;
    }
    int mid = (l+r)>>1;
    if (u <= mid)
        update(2*node, l, mid, u, val);
    if (u > mid)
        update(2*node+1, mid+1, r, u, val);
    update(node);
}

void get(int node, int l, int r, int ti)
{
    if (r <= ti)
    {
        ans = max(ans + tree[node].sum, tree[node].ti);
        return ;
    }
    int mid = (l+r)>>1;
    get(2*node, l, mid, ti);
    if (ti > mid)
    {
        get(2*node+1, mid+1, r, ti);
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> q;
    init();
    for (int i = 1; i <= q; i++)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            cin >> a[i] >> b[i];
            update(1, 1, maxn, a[i], b[i]);
        }
        if (c == '-')
        {
            int pos;
            cin >> pos;
            update(1, 1, maxn, a[pos], - b[pos]);
        }
        if (c == '?')
        {
            int ti;
            cin >> ti;
            ans = 0;
            get(1, 1, maxn, ti);
            cout << max(ans-ti, 0LL) << endl;
        }
    }
    return 0;
}
