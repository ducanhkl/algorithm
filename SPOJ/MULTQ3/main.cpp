#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;

int n, m;

int tree[5*maxn][4], f[5*maxn];

void process(int node, int num)
{
    int val[3];
    for (int i = 0; i < 3; i++)
        val[i] = tree[node][(i+num)%3];
    for (int i= 0 ; i < 3; i++)
        tree[node][i] = val[i];
    return ;
}

void push_down(int cha, int con)
{
    f[con] += f[cha];
    process(con, f[cha]);
}

void push_up(int node)
{
    for (int i = 0 ; i < 3; i++)
        tree[node][i] = tree[2*node][i] + tree[2*node+1][i];
    return ;
}

void update(int node, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return;
    if (u <= l && r <= v)
    {
        f[node] ++;
        process(node, 1);
        return;
    }
    if (f[node])
    {
        push_down(node, 2*node);
        push_down(node, 2*node+1);
        f[node] = 0;
    }
    int mid = (l+r)/2;
    update(2*node,l, mid, u, v);
    update(2*node+1, mid+1, r, u, v);
    push_up(node);
}

int query(int node, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return 0;
    if (u <= l && r <= v)
    {
        return tree[node][0];
    }
    if (f[node])
    {
        push_down(node, 2*node);
        push_down(node, 2*node+1);
        f[node] = 0;
    }
    int mid = (l+r)/2;
    int res1 = query(2*node, l, mid, u, v);
    int res2 = query(2*node+1, mid+1, r, u, v);
    return res1+res2;
}

void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node][0] = 1;
        return;
    }
    int mid = (l+r)>>1;
    build(2*node  , l    , mid);
    build(2*node+1, mid+1, r);
    tree[node][0] = tree[2*node][0]+tree[2*node+1][0];
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int _, x, y;
        cin >> _ >> x >> y;
        x++, y++;
        if ( _ == 0)
        {
            update(1, 1, n, x, y);
        } else
        {
            int ans = query(1, 1, n, x, y);
            cout << ans  << endl;
        }
    }
    return 0;
}
