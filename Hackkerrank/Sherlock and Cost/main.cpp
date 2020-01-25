#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100004
using namespace std;

ll a[maxn], dp[maxn][2], t, n;

void solve()
{
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + abs(a[i-1]-1));
        dp[i][1] = max(dp[i-1][0]+abs(a[i]-1), dp[i-1][1] + abs(a[i]-a[i-1]));
    }
}
int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
	while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(dp, 0, sizeof(dp));
        solve();
        cout << max(dp[n][1], dp[n][0]) << endl;
    }
	return 0;
}
