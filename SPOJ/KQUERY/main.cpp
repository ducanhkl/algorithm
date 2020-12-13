#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+100;

struct data
{
	int l, r, val, id;
} ask[maxn];

int n;

pair<int, int> a[maxn];

int ans[maxn], tree[maxn];

void
update(int x)
{
	for (; x < maxn; x += (x & (-x)))
	{
		tree[x]++;
	}
	return;
}

int
get(int x)
{
	int ans = 0;
	for (; x > 0; x -= (x & (-x)))
	{
		ans += tree[x];
	}
	return ans;
}

int
get(int l, int r)
{
	return get(r) - get(l - 1);
}

bool
cmp_by_val(data x, data y)
{
	return x.val < y.val;
}

int
main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		cin >> ask[i].l >> ask[i].r >> ask[i].val;
		ask[i].id = i;
	}
	sort(a + 1, a + n + 1);
	sort(ask + 1, ask + q + 1, cmp_by_val);
	int last = n;
	for (int i = q; i >= 1; i--)
	{
		while (last > 0 && a[last].first > ask[i].val)
		{
			update(a[last].second);
			last--;
		}
		ans[ask[i].id] = get(ask[i].l, ask[i].r);
	}
	for (int i = 1; i <= q; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
