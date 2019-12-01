#include <bits/stdc++.h>

using namespace std;


const int maxn = 3e6+100;


int a[maxn+100], b[maxn+100], n, m;

int f[5*(maxn+100)], tree[5*(maxn+100)];

void down(int cha, int con)
{
    f[con] += f[cha];
    tree[con] += f[cha];
}

void update(int node, int l, int r, int u, int v, int val)
{
    if (f[node])
    {
        down(node, 2*node);
        down(node, 2*node+1);
        f[node] = 0;
    }
    if (l > v || r < u)
        return ;
    if (u <= l && r <= v)
    {
        f[node] += val;
        tree[node] += val;
        return ;
    }
    int mid = (l+r)>>1;
    update(2*node, l, mid, u, v, val);
    update(2*node+1, mid+1, r, u, v, val);
    tree[node] = min(tree[2*node], tree[2*node+1]);
    return ;
}

int get(int node, int l, int r)
{
    if (l == r)
        return l;
    if (f[node])
    {
        down(node, 2*node);
        down(node, 2*node+1);
        f[node] = 0;
    }
    int mid = (l+r)>>1;
    if (tree[2*node+1] < 0)
        return get(2*node+1, mid+1, r);
    else
        return get(2*node, l, mid);
}

int main() {
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    memset(tree, 0, sizeof(tree));
    memset(f, 0, sizeof(f));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, 0, maxn, 0, a[i], -1);
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        update(1, 0, maxn, 0, b[i], 1);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int t, index, val;
        cin >> t >> index >> val;
        if (t == 1) {
            update(1, 0, maxn, 0, a[index], 1);
            a[index] = val;
            update(1, 0, maxn, 0, a[index], -1);
        } else {
            update(1, 0, maxn, 0, b[index], -1);
            b[index] = val;
            update(1, 0, maxn, 0, b[index], 1);
        }
        int ans = get(1, 0, maxn);
        if (ans == 0)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}