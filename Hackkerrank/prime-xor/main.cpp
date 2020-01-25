#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 1000000007

using namespace std;

ll d[10000], dp[1005][8200], a[1700];
int n;

vector <int > v;

void prime()
{
    for (int i = 2; i <= 8199; i++)
        if (!d[i])
            for (int j = i+i; j <= 8199; j+= i)
                d[j] = true;
    for (int j = 2; j <= 8199; j++)
        if (!d[j]) v.push_back(j);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	prime();
	int t;
	cin >> t;
	while (t--)
    {
        cin >> n;
        int x;
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            cin >> x, a[x-3500] ++;
        dp[0][3500] = (a[0]+1)/2;
        dp[0][0] = (a[0]+2)/2;
        for (int i = 1; i < 1005; i++)
            for (int j = 0; j < 8200; j++)
            {
                dp[i][j] = dp[i-1][j]*((a[i]+2)/2)%maxnum + dp[i-1][j^(i+3500)]*((a[i]+1)/2)%maxnum;
                dp[i][j] = dp[i][j] % maxnum;
            }
        ll ans = 0;
        for (int i = 0; i < v.size(); i++)
            ans += dp[1004][v[i]]%maxnum, ans = ans % maxnum;
        cout << ans << endl;
    }

	return 0;
}
