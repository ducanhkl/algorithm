#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
int a[maxn], n, p[8*maxn], tree[8*maxn], k, q[maxn], pre[maxn];

void down(int cha, int con)
{
    tree[con] += p[cha];
    p[con] += p[cha];
}

void update(int node, int l, int r, int u, int v)
{
    down(node, 2*node);
    down(node, 2*node+1);
    p[node] = 0;
    if (u > r || v < l)
        return;
    if (u <= l && v >= r)
    {
        tree[node]++;
        p[node] = 1;
        return;
    }
    int mid = (l+r) >> 1;
    update(node*2, l, mid, u, v);
    update(node*2+1, mid+1, r,u , v);
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

int get(int node, int l, int r, int u, int v)
{
    down(node, 2*node);
    down(node, 2*node+1);
    p[node] = 0;
    if (u > r || v < l)
        return 0;
    if (u <= l && v >= r)
        return tree[node];
    int mid = (l+r) >> 1;
    int res1 = get(2*node, l, mid, u, v);
    int res2 = get(2*node+1, mid+1, r, u, v);
    return max(res1, res2);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int top = 0;
    for (int i = n; i>= 1; i--)
    {
        while (top && a[q[top]] <= a[i])
            pre[q[top]] = i, top--;
        q[++top] = i;
    }
    for (int i = 1;  i <= n; i++)
    {
        update(1, 1, n, pre[i]+1, i);
        if (i >= k)
            cout << get(1, 1, n, i-k+1, i) << " ";
    }
    return 0;
}
