#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

ll l, r;
ll dp[20][170][1600];
int t;


ll calc(ll n)
{
    int dem = 0, a[20];
    while (n >0)
        a[++dem] = n%10, n = n /10;
    ll ans = 0;
    int t = 0, s = 0;
    for (int i = dem; i >= 1; i--)
    {
        for (int j = 0; j < a[i]; j++)
            if ((t+j< 163) && (s+j*j < 1469))
            ans += dp[i-1][t+j][s+j*j];
        t += a[i];
        s += a[i]*a[i];
    }
    ans += dp[0][t][s];
    return ans;
}
int main()
{
    memset(dp, 0, sizeof(dp));
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	for (int i = 0; i <= 162; i++)
        for (int j = 0; j <= 1458; j++)
            if (__gcd(i, j) == 1) dp[0][i][j] = 1;
    for (int k = 1; k <= 18; k++)
        for (int i = 0; i <= 162; i++)
            for (int j = 0; j <= 1458; j++)
                for (int t = 0; t <= 9; t++)
                    if (t + i < 162 && t*t +j< 1459)
                        dp[k][i][j] += dp[k-1][i+t][j+t*t];
	cin >> t;
    while (t--)
    {
        cin >> l >> r;
        if (l > r)
            cout << 0 << endl;
        else cout << max(1LL, calc(r)-calc(l-1)) << endl;
    }
	return 0;
}
