#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000004
using namespace std;

int t[4*maxn], a[maxn], d[maxn], n, k;

int init(int node, int l, int r)
{
    if (l == r)
        return t[node] = a[l];
    int g = (l+r)/2;
    init(2*node, l, g);
    init(2*node+1,g +1, r);
    t[node] = max(t[2*node], t[2*node+1]);
    return 0;
}

int update(int node, int l, int r,int u, int v, int k)
{
    if (d[node] != 0)
    {
        d[2*node] = d[node];
        d[2*node+1] = d[node];
        t[node] = d[node];
        d[node] = 0;
    }
    if (l >= u && r <= v)
    {
        d[node] = k;
        t[node] = k;
        return 0;
    }
    if ( l > v || r < u)
        return 0;
    int g = (l+r)>>1;
    update(2*node,l , g, u, v, k);
    update(2*node+1, g+1, r, u, v, k);
    t[node] = max(t[2*node+1], t[2*node]);
    return 0;
}

int get(int node, int l, int r, int u , int v)
{
    if (d[node] != 0)
    {
        d[2*node] = d[node];
        d[2*node+1] = d[node];
        t[node] = d[node];
        d[node] = 0;
    }
    if ( l > v || r < u)
        return -maxnum;
    if (l >= u && r <= v)
    {
        return t[node];
    }
    int g = (l+r)>>1;
    return max(get(2*node, l, g, u, v), get(2*node+1, g+1, r, u, v));
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    init(1, 1, n);
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        int k = get(1, 1, n, u, v+u-1);
        update(1, 1, n, u, v+u-1, k+1);
        cout << k + 1<< endl;
    }
	return 0;
}
