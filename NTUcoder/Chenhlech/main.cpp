#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100001
using namespace std;

ll a[maxn], n, u, v, q;

int findm(int l,int r)
{
    ll k, t1 = l, t2 = r, sum1, sum2, ans = a[r] - a[l-1];
    while (l < r)
    {
        k = (r+l)/2;
        sum1 = a[t2] - a[k], sum2= a[k] - a[t1-1];
        if (sum1 == sum2)
            return 0;
        ans = min(ans, abs(sum1 - sum2));
        if (sum1 < sum2)
            r = k;
        else l = k+1;
    }
    return ans;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
        cin >> a[i], a[i]+= a[i-1];
    for (int i = 1; i <= q; i++)
    {
        cin >> u >> v;
        cout << findm(u, v) << endl;
    }
	return 0;
}
