#include <bits/stdc++.h>
#define ll __int
#define maxn 1000005

using namespace std;

ll a, b, k;

ll tinh(ll x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return a % k;
    ll y = tinh(x/2);
    if (x % 2 == 0)
        return (y*y)%k;
    else return (((y*y)%k)*(a%k))%k;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
	int t;
	cin >> t;
	while (t --)
    {
        cin >> a >> b >> k;
        cout << tinh(b) << endl;
    }
    return 0;
}
