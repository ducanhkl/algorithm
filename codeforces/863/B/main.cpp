#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100005

using namespace std;

ll a[maxn], res = maxnum ,n, b[maxn], c[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	n *= 2;
	for (int i = 1;i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
        {
            ll ans = 0, t = -1;
            for (int k = 1; k <= n; k++)
                if (k != i && k != j)
                    ans += a[k]*t, t *= -1;
            res = min(ans, res);
        }
    cout << res;
	return 0;
}
