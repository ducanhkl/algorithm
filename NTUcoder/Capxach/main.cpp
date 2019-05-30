#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 300
#define maxm 100

using namespace std;

int a[maxm];
ll dp[maxn];
int n, m;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
        cin >> a[i];
    sort (a+1, a+m+1);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= n-a[i]; j++)
            dp[j + a[i]] += dp[j];
    cout << dp[n];
	return 0;
}
