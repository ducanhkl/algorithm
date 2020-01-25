#include<bits/stdc++.h>

#define for1(i,n) for(i=1;i<=n;++i)

using namespace std;

#define maxn 20

int n;

int fOPT = INT_MAX, i, j;

int x[maxn], chuaxet[maxn], cmin;

int cost[maxn + 1][maxn + 1], l = 0, ans = INT_MAX, g = 0;

void init()
{
	x[1] = 1;
	for (i = 0;i <= n;i++)
		chuaxet[i] = 1;
}

void solve(int k)
{
	for (int j = 2;j <= n;j++)
	{
		if (chuaxet[j])
		{
			x[k] = j;
			chuaxet[j] = 0;
			l+=cost[x[k - 1]][x[k]];
			if (k == n)
			{
				ans = min(ans,l + cost[x[k]][1]);
			}
			else if (l + (n-k+1)*cmin < ans)
				solve(k + 1);
			chuaxet[j] = 1;
			l -= cost[x[k - 1]][x[k]];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
	cmin = INT_MAX;
	cin >> n;
	for1(i,n)
		for1(j,n)
		{
			cin >> cost[i][j];
			if (cost[i][j] != 0)
				cmin = min(cmin, cost[i][j]);
		}
	init();
	solve(2);
	cout << ans<<endl;
	//system("pause");
	return 0;
}
