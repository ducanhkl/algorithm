#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;
ll n, m, k;
ll h, c;
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m >> k;
	h = ceil((double)k/m);
	c = k%m;
	cout << h * c;
	return 0;
}
