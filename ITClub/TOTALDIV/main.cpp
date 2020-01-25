#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

ll n;

int main()
{
    int t;
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
	while(t--)
    {
        ll ans = 0;
        cin >> n;
        for (ll i = 1; i <= sqrt(n); i++)
            if (n%i == 0)
                {
                    ans += i;
                    ans += n/i;
                }
        long long g = sqrt(n);
        if (g*g == n)
            ans -= sqrt(n);
        cout << ans << endl;
    }
	return 0;
}
