#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000005
using namespace std;

ll dd[maxn], a[maxn];
int n;

int main()
{
    int t;
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
	while (t --)
    {
        ll ans = 0;
        memset(dd, 0, sizeof(dd));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = n; i >= 1; i--)
            dd[i] = dd[i+1]+a[i];
        for (int i = 1; i <= n; i++)
            ans += -(long long)(n-i)*a[i] + dd[i+1];
        cout << ans << endl;
    }
	return 0;
}
