#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 51000

using namespace std;

ll a[maxn], m, n;

struct data
{
    ll l;
    ll r;
    ll sum;
    ll ans;
} tree[4*maxn];

data tao(ll _l, ll _r, ll _sum, ll _ans)
{
    data ans;
    ans.l = _l;
    ans.r = _r;
    ans.sum = _sum;
    ans.ans = _ans;
    return ans;
}
void init(int node, int l, int r)
{
    if (l == r)
        {
            tree[node] = tao(a[l], a[l], a[l], a[r]);
            return;
        }
    int g = (l+r) >> 1;
    init(2*node,l,g);
    init(2*node+1,g+1, r);
    tree[node].l = max(tree[2*node].l, tree[2*node].sum + tree[2*node+1].l);
    tree[node].r = max(tree[2*node].r+tree[2*node+1].sum, tree[2*node+1].r);
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    tree[node].ans = max(max(tree[2*node].ans, tree[2*node+1].ans), tree[2*node].r + tree[2*node+1].l);
    return;
}

data get(int node, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return tao(INT_MIN, INT_MIN, INT_MIN,INT_MIN);
    if (l >= u&& r <=v)
        return tree[node];
    int g = (l+r)/2;
    int k = node*2;
    data u1 = get(k, l, g, u, v);
    data u2 = get(k+1, g+1, r, u, v);
    data res;
    res.l = max(u1.l, u1.sum+u2.l);
    res.r = max(u1.r+u2.sum, u2.r);
    res.sum = u1.sum+u2.sum;
    res.ans = max(max(u1.ans, u2.ans), u1.r+u2.l);
    return res;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    init(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << get(1,1,n,u,v).ans << endl;
    }
	return 0;
}
