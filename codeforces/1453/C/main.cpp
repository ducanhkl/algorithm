#include <bits/stdc++.h>

using namespace std;

const int maxn = 2021;

int n;
int ans[20];
char a[maxn][maxn], b[maxn][maxn];

void out()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << (int)a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int
solve(int x)
{
	int res = 0;
	int vtt = n+1, vtd = 0;
	for (int j = 1; j <=  n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i][j] == x)
			{
				vtt = min(i, vtt);
				vtd = max(i, vtd);
				res = max(res, (i-vtt)*max(j-1, n-j));
				res = max(res, (vtd-i)*max(j-1, n-j));
			}
		}

	}
	return max(res, 0);
}

void next()
{
	for (int i  = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			b[i][j] = a[n-j+1][i];
		}
	}
	for (int i  = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

int
main()
{
	// freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	while (test--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> a[i][j];
				a[i][j] -= '0';
			}
		}
		// reset();
		for (int i = 0; i <= 9; i++)
		{
			ans[i] = solve(i);
			next();
			// out();
			ans[i] = max(ans[i], solve(i));
			next();
			ans[i] = max(ans[i], solve(i));
			next();
			ans[i] = max(ans[i], solve(i));
		}
		for (int i = 0; i <= 9; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
