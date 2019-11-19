#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100004

using namespace std;

ll t;
ll a[maxn], b[maxn];
int n;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i], t += a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(b+1, b+n+1);
    if (b[n] + b[n-1] >= t)
        cout << "YES";
    else cout << "NO";
	return 0;
}
