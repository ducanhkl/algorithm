#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int t;
ll n;

ll findt (ll x)
{
    ll ans = 0;
    ll m = sqrt(x);
    if (m*m == x)
        ans -= m;
    for (ll i = 1; i <= sqrt(x); i++)
        if (x % i == 0)
            ans += i + (x/i);
    return ans;
}
int main()
{
    //freopen("inp.ttx", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll k = findt (n);
        ll h = findt (k);
        if (2LL*n == h)
            cout << "YES";
        else cout << "NO";
        cout << endl;
    }
	return 0;
}
