#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100004

using namespace std;

ll a[maxn], s, ans;
int n, t;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
	while (t--)
    {
        ans = maxnum;
        s = 0;
        ll t = 0, l = 1;
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            t += a[i];
            while (t >= s)
            {
                ans = min(ans, i-l+1);
                t -= a[l++];
            }
        }
        if (ans == maxnum)
            cout << 0 << endl;
        else cout << ans << endl;
    }
	return 0;
}
