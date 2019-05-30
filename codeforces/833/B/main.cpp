#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

int tree[4*maxn], dp[70][maxn], tr[maxn], f[4*maxn], a[maxn];


void push(int node1, int node2)
{
    tree[node2] += f[node1];
    f[node2] += f[node1];
}
void init(int node, int l, int r, int k)
{
    if (l == r)
    {
        tree[node] = dp[k][l];
        return ;
    }
    int mid = (l+r) >> 1;
    init(2*node, l, mid, k);
    init(2*node+1, mid+1, r, k);
    tree[node] = max(tree[2*node], tree[2*node+1]);
    return ;
}

void update(int node, int l, int r, int u, int v)
{
    if (f[node])
    {
        push(node, 2*node);
        push(node, 2*node+1);
        f[node] = 0;
    }
    if (l >= u && r <= v)
    {
        f[node] += 1;
        tree[node] += 1;
        return;
    }
    if (l > v || r < u)
        return ;
    int mid = (l+r) >> 1;
    update(2*node, l, mid, u, v);
    update(2*node+1, mid+1, r, u, v);
    tree[node] = max(tree[2*node], tree[2*node+1]);
    return;
}

int get(int node, int l, int r, int u, int v)
{
    if (f[node])
    {
        push(node, 2*node);
        push(node, 2*node+1);
        f[node] = 0;
    }
    if (l >= u && r <= v)
        return tree[node];
    if (l > v || r < u)
        return INT_MIN;
    int mid = (l+r) >> 1;
    return max(get(2*node, l, mid, u, v), get(2*node+1, mid+1, r, u, v));
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int n, k;
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
    {
        if (i == 2)
            i = 2;
        memset(tr, 0, sizeof(tr));
        memset(tree, 0, sizeof(tree));
        memset(f, 0, sizeof(f));
        init(1, 0, n, i-1);
        for (int j = 1; j <= n; j++)
        {
            update(1, 0, n, tr[a[j]], j-1);
            tr[a[j]] = j;
            dp[i][j] = get(1, 0, n, 0, j-1);
        }
    }
    cout << dp[k][n];
    return 0;
}
