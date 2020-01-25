#include <bits/stdc++.h>

using namespace std;

const  int maxn = 1e5+100;

int n, m;
int a[maxn], b[maxn];
int tree[5*maxn], f[5*maxn];

void init()
{
    sort (b+1, b+n+1);
    m = unique(b+1, b+n+1) - b - 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(b+1, b+m+1, a[i]) - b;
    }
}

void push(int cha, int con)
{
    tree[con] += f[cha];
    f[con] += f[cha];
}

void update(int node, int l, int r, int u, int v, int val)
{
    if (r < l)
        return ;
    if (f[node])
    {
        push(node, 2*node);
        push(node, 2*node+1);
        f[node] = 0;
    }
    if (l > v || r < u)
    {
        return ;
    }
    if (u <= l && r <= v)
    {
        tree[node] += val;
        f[node] += val;
        return ;
    }
    int mid = (l+r)/2;
    update(2*node, l, mid, u, v, val);
    update(2*node+1, mid+1, r, u, v, val);
    tree[node] = min(tree[2*node], tree[2*node+1]);
    return ;
}

void solve()
{
    int ans = -1;
    if (a[1] < a[2])
        ans = 1;
    update(1, 1, m, 1, a[1], -1);
    update(1, 1, m, 1, a[2]-1, 1);
    for (int i = 2; i <= n/2; i++)
    {
        update(1, 1, n, 1, a[i]-1,-1);
        update(1, 1, n, 1, a[i],-1);
        update(1, 1, n, 1, a[2*i-1]-1, 1);
        update(1, 1, n, 1, a[2*i] - 1, 1);
        if (tree[1] >= 0)
            ans = i;
    }
    cout << ans;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    init();
    solve();
    return 0;
}
