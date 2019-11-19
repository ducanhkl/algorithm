#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000005

using namespace std;

ll n, a[maxn], b[maxn], c[maxn], bb[maxn], cc[maxn];
ll ans = INT_MIN;

int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        b[i] = abs(a[i] - a[i+1]);
        if (i%2 == 0)
            b[i] = -b[i];
    }
    for (int i = 1; i < n; i++)
    {
        c[i] = abs(a[i] - a[i+1]);
        if (i%2 == 1)
            c[i] = -c[i];
    }
    b[0] = 0;
    c[0] = 0;
    n --;
    for (int  i = 1; i <= n; i++)
        b[i] = b[i-1]+b[i], c[i] = c[i-1]+c[i];
    bb[n] = b[n];
    cc[n] = c[n];
    for (int i = n-1; i >= 0; i--)
        bb[i] = max(bb[i+1], b[i]), cc[i] = max(cc[i+1], c[i]);
    for (int i = 0; i < n; i++)
        if (i % 2== 0)
            ans = max(ans, bb[i+1]-b[i]);
        else ans = max(ans, c[i+1]-c[i]);
    cout << ans;
	return 0;
}
