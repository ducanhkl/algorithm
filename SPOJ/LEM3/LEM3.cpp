#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1004

using namespace std;

int a[maxn][maxn], n;
ll dp[1<<17][30];

int get(int x, int y)
{
    return (x >> (y-1))&1;
}
int offbit(int x, int y)
{
    return (x ^ (1<<(y-1)));
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 0; i < (1<<n); i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = maxnum;
    for (int i = 1; i < (1<<n); i++)
    {
        int t[20], dem = 0;
        memset(t, 0, sizeof(t));
        for (int j = 1; j <= n; j++)
            if (get(i, j)) t[++dem] = j;
        if (dem == 1)
        {
            dp[i][t[dem]] = 0;
            continue;
        }
        for (int j = 1; j <= dem; j++)
            for (int k = 1; k <= n; k++)
                if (get(i, k) && t[j] != k)
        {
            int i2 = offbit(i, t[j]);
            dp[i][t[j]] = min(dp[i][t[j]], dp[i2][k] + a[k][t[j]]);
        }
    }
    ll res = maxnum;
    for (int i = 1; i <= n; i++)
        res = min(res, dp[(1<<n)-1][i]);
    cout << res;
	return 0;
}
