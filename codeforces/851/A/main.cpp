#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

ll n, k, t;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> k >> t;
	t = t%(k*2 + n-k);
    if (t < k)
        cout << t;
    if (t >= k && t <= n)
        cout << k;
    if (t > n)
        cout << k - (t-n);
	return 0;
}
