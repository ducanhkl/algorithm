#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;
long long l, r, x, y, k;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> l >> r >> x >> y >> k;
    for (int i = x; i <= y; i++)
        if (i*k >= l && i*k <= r)
            return cout << "YES",0;
    cout << "NO";
    return 0;
}
