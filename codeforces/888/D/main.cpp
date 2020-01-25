#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

ll n, k;
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> k;
	if (k == 1)
        return cout << 1, 0;
    if (k == 2)
        return cout << n*(n-1)/2+1, 0;
    if ( k == 3)
        return cout << n*(n-1)*(n-2)*5/6 - n*(n-1)+1, 0;
    cout << n*(n-1)*(n-2)*(n-3)*23/24 - n*(n-1)*(n-2)*5/6 + n*(n-1) - n*(n-1)/2 + 1;
	return 0;
}
