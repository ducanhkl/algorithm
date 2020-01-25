#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006
using namespace std;

ll n;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	ll res = -1, ans = maxnum;
	for (int i = 0; i <= n/4; i++)
        if ((n - 4*i)%7 == 0)
    {
        if (i+(n - 4*i)/7 < ans)
        {
            res = i;
            ans = i+(n - 4*i)/7;
        }
    }
    if (res == -1)
        return cout << res, 0;
    for (int i = 1; i <= res; i++)
        cout << 4;
    for (int i = 1; i <= (n-4*res)/7; i++)
        cout << 7;
	return 0;
}
