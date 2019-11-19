#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

ll n, a[1000006];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ll r = 0;
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 0; i <= n; i++)
        cin >> a[i];
    for (int i = n; i > 1; i--)
        if ((a[i]+r)%i != 0)
            return cout << "No" ,0;
        else r += (a[i]+r)/i;
    cout << "Yes";
	return 0;
}
