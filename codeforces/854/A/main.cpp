#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	pair <int, int> x;
	x.first = 1; x.second = n - 1;
	for (int i = 2; i <= n/2; i++)
        if (x.first * (n-i) < x.second * i && __gcd(i, n-i) == 1)
            x.first = i, x.second = n-i;
    cout << x.first << " " << x.second;
	return 0;
}
