#include <bits/stdc++.h>

using namespace std;


const int maxn = 3e5+100;

int n;
long long a[maxn];
int b[maxn];
long long ans = 0;
vector <int> e[maxn], v1, v2;

int
dfs(int u, int par)
{
	for (auto v : e[u])
	{
		if (v == par )
			continue;
		dfs(v, u);
		if (a[v] > 0)
		{
			a[u] += a[v];
		}
	}
	if (a[u] > 0)
	{
		v1.push_back(u);
	} else
	{
		v2.push_back(u);
	}
	ans += a[u];
}

int
main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		if (b[i] != -1)
		{
			e[b[i]].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (b[i] == -1)
		{
			dfs(i, 0);
		}
	}
	cout << ans << endl;
	for (auto v : v1)
	{
		cout << v << " ";
	}
	cout << endl;
	reverse(v2.begin(), v2.end());
	for (auto v : v2)
	{
		cout << v << " ";
	}
	return 0;
}
