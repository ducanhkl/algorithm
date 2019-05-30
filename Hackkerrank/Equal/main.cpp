#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 10004

using namespace std;

ll a[maxn], ans;
int n, t;

void solve()
{
    sort(a+1, a+n+1);
    for (int i = 0; i <3; i++)
    {
        ll res = 0;
        for (int j = 1; j <= n; j++)
            {
                ll t = a[j]-a[1] + i;
                res += t/5 + (t%5)/ 2 + ((t%5)%2)/1;
            }
        ans = min(ans, res);
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
        ans = maxnum;
        solve();
        cout << ans << endl;
    }
	return 0;
}
