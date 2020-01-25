#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100004

using namespace std;

ll n, k, a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin  >> n >> k;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = a[1], dem = 0, i;s
    for (i = 2; i <= n; i++)
    {
        if (ans < a[i])
        {
            ans = a[i];
            dem = 1;
        }
        else dem ++;
        if (dem == k)
            return cout << ans, 0;
    }
    cout << ans;
    return 0;
}
