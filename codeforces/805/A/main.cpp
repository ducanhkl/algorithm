#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int l, r;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> l >> r;
	if (l == r)
        cout << l;
    else cout << 2;
	return 0;
}
