#include <bits/stdc++.h>

using namespace std;

const int maxn = 3*1e5+100;

struct data{
    int l, r, sum;
} tree[maxn*100];

int pos[maxn];
int n, q, id = 0;

int add(int node, int l, int r, int value)
{
    int now = ++id;
    tree[now] = tree[node];
    tree[now].sum += 1;
    if (l == r)
        return now;
    int mid = (l+r)>>1;
    if (value > mid)
        tree[now].r = add(tree[node].r, mid+1, r, value);
    else
        tree[now].l = add(tree[node].l, l, mid, value);
    return now;
}

int get(int u, int v, int l, int r, int value)
{
    if (tree[v].sum - tree[u].sum <= value)
        return -1;
    if (l == r)
        return l;
    int mid = (l+r)>>1;
    int ans = get(tree[u].l, tree[v].l, l, mid, value);
    if (ans == -1)
        return get(tree[u].r, tree[v].r, mid+1, r, value);
    else
        return ans;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(tree, 0, sizeof(tree));
    memset(pos, 0, sizeof(pos));
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pos[i] = add(pos[i-1], 1, n, x);
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int res = get(pos[l-1], pos[r], 1, n, (r-l+1)/k);
        cout << res << endl;
    }
    return 0;
}
