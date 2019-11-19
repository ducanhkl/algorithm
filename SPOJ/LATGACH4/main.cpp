#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define MOD 111539786

using namespace std;

class maxtrix
{
    public :
        ll x;
        ll y;
        ll z;
        ll t;
        maxtrix(ll _x, ll _y, ll _z, ll _t)
        {
            x = _x%MOD;
            y = _y%MOD;
            z = _z%MOD;
            t = _t%MOD;
        }
};
maxtrix operator * (maxtrix x, maxtrix y)
{
    ll _x = (x.x*y.x + x.y*y.z)%MOD;
    ll _y = (x.x*y.y + x.y*y.t)%MOD;
    ll _z = (x.z*y.x + x.t*y.z)%MOD;
    ll _t = (x.z*y.y + x.t*y.t)%MOD;
    return maxtrix(_x, _y, _z, _t);
}
maxtrix power(maxtrix x, int y)
{
    if (y == 1)
        return x;
    maxtrix ans = power(x, y/2);
    if (y%2)
        return (ans*ans)*x;
    else return ans*ans;
}
int main()
{
    int t, n;
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> t;
    while(t --)
    {
        cin >> n;
        maxtrix x = maxtrix(0, 1, 1, 1);
        maxtrix y = power(x, n);
        cout << y.t << endl;
    }
    return 0;
}
