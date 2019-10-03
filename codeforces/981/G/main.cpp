#include <bits/stdc++.h>

using namespace std;

const int maxn = 300000, mod = 998244353, maxm = 13000000;
int n, q, ls;
int sum[maxm], lf[maxm], rg[maxm], m[maxm], p[maxm];

void up(int node)
{
    sum[node] = (sum[lf[node]] + sum[rg[node]])%mod;
}

int mul(int node, int val)
{
    if (node == 0)
        node = ++ls, m[node] = 1, p[node] = 0;
    sum[node] = (1LL*sum[node]*val)%mod;
    m[node] = (1LL*m[node]*val)%mod;
    p[node] = (1LL*p[node]*val)%mod;
    return node;
}

int add(int node, int l, int r, int val)
{
    if (node == 0)
        node = ++ls, m[node] = 1, p[node] = 0;
    sum[node] = (sum[node] + 1LL*val*(r-l+1) % mod)%mod;
    p[node] = (p[node] + val)%mod;
    return node;

}

void push_down(int node, int l, int r)
{
    int mid = (l+r)/2;
    lf[node] = mul(lf[node], m[node]);
    rg[node] = mul(rg[node], m[node]);
    m[node] = 1;
    add(lf[node], l, mid, p[node]);
    add(rg[node], mid+1, r, p[node]);
    p[node] = 0;
}

void update(int node1, int node2, int l, int r, int u, int v, int val)
{
    if (u <= l && r <= v)
    {
        if (sum[node2] == r-l+1)
        {
            mul(node1, 2);
            return ;
        } else
        if (sum[node2] == 0)
        {
            add(node1, l, r, 1);
            add(node2, l, r, 1);
            return ;
        }
    }
    push_down(node1, l, r);
    push_down(node2, l, r);
    int mid = (l+r)>>1;
    if (u <= mid)
        update(lf[node1], lf[node2], l, mid, u, v, val);
    if (v > mid)
        update(rg[node1], rg[node2], mid+1, r, u, v, val);
    up(node1);
    up(node2);
}

int get(int node, int l, int r, int u, int v)
{
    push_down(node, l, r);
    if (u <= l && r <= v)
        return sum[node];
    int mid = (l+r)>>1;
    long long ans = 0;
    if (u <= mid)
        ans += get(lf[node], l, mid, u, v);
    if (v > mid)
        ans += get(rg[node], mid+1, r, u, v);
    ans %= mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("inp.txt", "r", stdin);
    cin >> n >> q;
    ls = n+1;
    for (int i = 1; i <= n+1; i++)
        m[i] = 1, p[i] = 0;
    for (int i = 1 ; i <= q; i++)
    {
        int t, l, r, val;
        cin >> t >> l >> r;
        if (t == 2)
        {
            int ans = get(1, 1, n, l, r);
            cout << ans << endl;
        } else
        {
            cin >>  val;
            update(1, val+1, 1, n, l, r, val);
        }
    }
}
