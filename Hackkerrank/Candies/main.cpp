#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100004

using namespace std;

int a[maxn], dp[maxn], n, ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i], dp[i] = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] > a[i-1])
            dp[i] = dp[i-1]+1;
    for (int i = n-1; i > 0; i--)
        if (a[i] > a[i+1])
            dp[i] = max(dp[i], dp[i+1]+1);
    for (int i = 1; i <= n; i++)
        ans += dp[i];
    cout << ans;
	return 0;
}
