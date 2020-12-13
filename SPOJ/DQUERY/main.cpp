#include "bits/stdc++.h";

using  namespace std;

const int maxn = 5e4+100;

struct data
{
	int sum, l, r;
} tree[30*maxn];

int n, cnt;
int a[maxn], last[maxn], pos[maxn];


void compress()
{
	vector <int> b;
	for (int i = 1; i <= n; i++)
	{
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(b.begin(), b.end(),a[i]) - b.begin()+1;
	}
	return ;
}

int add(int cha, int l, int r, int pos)
{
	cnt ++;
	int con = cnt;
	tree[con] = tree[cha];
	tree[con].sum ++;
	if (l == r)
	{
		return con;
	}
	int mid = (l+r) >> 1;
	if (pos <= mid)
	{
		tree[con].l = add(tree[con].l,l, mid, pos);
	} else
	{
		tree[con].r = add(tree[con].r, mid+1, r, pos);
	}
	return con;
}

int get_ans(int node,int l, int r, int u, int v)
{
	if (v < l || u > r)
	{
		return 0;
	}
	if (u <= l && r <= v)
	{
		return tree[node].sum;
	}
	int mid = (l+r)>>1;
	int res1 = get_ans(tree[node].l, l, mid, u, v);
	int res2 = get_ans(tree[node].r, mid+1, r, u, v);
	return res1+res2;
}

void solve()
{
	for (int i = 1; i <= n; i++)
	{
		last[a[i]] = n+1;
	}
	for (int i = n; i>= 1; i--)
	{
		pos[i] = add(pos[i+1], 1, n+1, last[a[i]]);
		last[a[i]] = i;
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n;i ++)
	{
		cin >> a[i];
	}
	compress();
	solve();
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int l, r;
		cin >> l >> r;
		int ans =(r-l+1) - get_ans(pos[l], 1, n+1,1, r);
		cout << ans << endl;
	}
}

/*
 * Mo Solutions

#include <bits/stdc++.h>

using namespace std;


struct query
{
    int l, r, pos;
};

query b[200001];
int res[200001];
int a[300000], n, q, ans = 0;
int sl[1000006];


bool cmpbymo(query x, query y)
{
    int s = sqrt(n);
    if (x.l/s != y.l/s)
        return x.l/s < y.l/s;
    else return x.r < y.r;
}

bool cmpbypos(query x, query y)
{
    return x.pos < y.pos;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    cin >> q;
    for (int i = 1; i <= q; i++)
        scanf("%d", &b[i].l), scanf("%d", &b[i].r), b[i].pos = i;
    sort(b+1, b+q+1, cmpbymo);
    for (int i = b[1].l; i <= b[1].r; i++)
    {
        if (sl[a[i]] == 0)
            ans ++;
        sl[a[i]] ++;
    }
    res[b[1].pos] = ans;
    for (int i = 2; i <= q; i++)
    {
        for (int j = b[i-1].l; j < b[i].l; j++)
        {
            sl[a[j]] --;
            if (sl[a[j]] == 0)
                ans--;
        }
        for (int j = b[i-1].l-1; j >= b[i].l; j--)
        {
            if (sl[a[j]] == 0)
                ans++;
            sl[a[j]] ++;
        }
        for (int j = b[i-1].r; j > b[i].r; j--)
        {
            sl[a[j]] --;
            if (sl[a[j]] == 0)
                ans--;
        }
        for (int j = b[i-1].r+1; j <= b[i].r; j++)
        {
            if (sl[a[j]] == 0)
                ans++;
            sl[a[j]] ++;
        }
        res[b[i].pos] = ans;
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n",res[i]);
    return 0;
}
*/