#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000004

using namespace std;

int a[maxn], b[maxn], minn = 1, maxx = 1, dem = 0, gtmax, gtmin, n, m;
struct data
{
    int _min, _max;
};

data t[4*maxn];

int init(int node, int l, int r)
{
    if (l == r)
        return t[node]._max = t[node]._min = b[l];
    int g = (l+r) >> 1;
    init(2*node,l, g);
    init(2*node+1,g+1, r);
    t[node]._min = min(t[2*node]._min, t[2*node+1]._min);
    t[node]._max = max(t[2*node]._max, t[2*node+1]._max);
    return 0;
}

int get(int node, int l, int r, int u,int v)
{
    if (l > v || r < u)
        return 0;
    if (l >= u && r <= v)
    {
        gtmax = max(t[node]._max, gtmax);
        gtmin = min(gtmin, t[node]._min);
        return 0;
    }
    int g = (l+r) >> 1;
    get(2*node, l, g, u, v);
    get(2*node+1, g+1, r, u, v);
    return 0;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    a[n+1] = -maxnum;
    a[0] = maxnum;
    for (int i = 1; i <= m; i++)
    {
        if (a[minn] > a[i])
            minn = i;
        if (a[maxx] < a[i])
            maxx = i;
    }
    int k = (a[m]-a[1])/abs(a[m] - a[1]);
    init(1, 1, n);
    for (int i = 1; i<= n-m+1; i++)
    {
        gtmax = -maxnum, gtmin = maxnum;
        get(1, 1, n, i, i+m-1);
        if (b[i+minn-1] == gtmin && b[i+maxx-1] == gtmax)
            if (k*(b[i+m-1] - b[i]) > 0)
            dem ++;
    }
    cout << dem;
	return 0;
}
