#include <bits/stdc++.h>

using namespace std;

const int maxn = 4000;
const int maxm = 2e5+100;

struct ask_me
{
	int x, y;
	int ans;
} ask[maxn];

struct edge
{
	int x, y, c;
} e[maxm];

int root[maxn];

int n, m, q;

bool
cmp(edge x, edge y)
{
	return x.c < y.c;
}

int
get_root(int u)
{
	if (root[u] == 0)
		return u;
	return (root[u] = get_root(root[u]));
}

void
update_ans(int val)
{
	int u, v;
	for (int j = 1; j <= q; j++)
	{
		if (ask[j].ans)
		{
			continue;
		}
		u = ask[j].x;
		v = ask[j].y;
		u = get_root(u);
		v = get_root(v);
		if (u == v)
		{
			ask[j].ans = max(ask[j].ans, val);
		}
	}
}

void
init()
{
	for (int i = 1; i <= m; i++)
	{
		cin >> e[i].x >> e[i].y >> e[i].c;
	}
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		cin >> ask[i].x >> ask[i].y;
	}
}

void
solve()
{
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		int u = e[i].x;
		int v = e[i].y;
		u = get_root(u);
		v = get_root(v);
		if (u != v)
		{
			root[v] = u;
		}
		update_ans(e[i].c);
	}
}

int
main()
{
	freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	init();
	solve();
	for (int i = 1; i <= q; i++)
	{
		cout << ask[i].ans << endl;
	}
	return 0;
}

