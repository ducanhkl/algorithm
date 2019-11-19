#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

ll n, s, t;

bool check(ll x)
{
    ll sum = x;
    while (x!= 0)
    {
        sum -= x%10;
        x /= 10;
    }
    return sum >= s;
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> s;
	t = s;
	while (!check(++t) && t <= n);
    cout << max(n-t+1, 0LL);
	return 0;
}
