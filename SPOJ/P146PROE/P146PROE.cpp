#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1004

using namespace std;

char a[101][10001];
ll  b[101][10001], c[101][10001];
int n, m;
ll ans, res = maxnum;

int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        b[i][0] = c[i][m+1] = -maxnum;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        b[i][j] = b[i][j-1];
        if (a[i][j] == '1')
            b[i][j] = j;
    }
    for (int i = 1; i <= n; i++)
        for (int j  = m; j >= 1; j --)
    {
        c[i][j] = c[i][j+1];
        if (a[i][j] == '1')
            c[i][j] = j;
    }
    for (int j = 1; j <= m; j++)
    {
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans += min(j-b[i][j], m-c[i][j] + j);
        res = min(ans, res);
    }
    if (res >= maxnum)
        return cout << -1, 0;
    cout << res;
	return 0;
}
