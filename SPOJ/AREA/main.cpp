#include <bits/stdc++.h>

using namespace std;


const int maxn = 6e4+100;

struct no
{
    int cnt;
    long long len;
} tree[maxn*5];


struct point
{
    int x;
    long long l, r;
    int t;
} a[maxn*4];

bool cmp(point x, point y)
{
    if (x.x == y.x)
        return x.t < y.t;
    return x.x < y.x;
}

int n, m;
long long ans;


void update(int node, int l, int r, int u, int v, int val)
{
    if (l > v || r < u)
    {
        return ;
    }
    if (u <= l && r <= v)
    {
        tree[node].cnt += val;
        if (val == 1)
        {
            tree[node].len = r-l+1;
            return ;
        }
        if (tree[node].cnt == 0)
        {
            if (l < r)
                tree[node].len = tree[2*node].len + tree[2*node+1].len;
            else
                tree[node].len = 0;
            return ;
        }
        return ;
    }
    int mid = (l+r)/2;
    update(2*node, l, mid, u, v, val);
    update(2*node+1, mid+1, r, u, v, val);
    if (l < r && tree[node].cnt == 0)
        tree[node].len = tree[2*node].len+tree[2*node+1].len;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1;  i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[++m] = {x1, y1+1, y2, 1};
        a[++m] = {x2, y1+1, y2, -1};
    }
    sort (a+1, a+m+1, cmp);
    for (int i = 1; i <= m; i++)
    {
        ans += (tree[1].len)*(a[i].x - a[i-1].x);
        update(1, 1, maxn, a[i].l, a[i].r, a[i].t);
    }
    cout << ans << endl;
    return 0;
}