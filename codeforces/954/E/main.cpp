#include <bits/stdc++.h>
#define maxn 300000

using namespace std;

typedef long double ll;
pair <ll, ll> a[maxn];
int n, t;
ll l = 0, r = 0, mid;

ll calc(ll m)
{
    ll res = 0, _m = m;
    if (m == 0)
        return 0;
    int pos = 1;
    while (m != 0 && pos <= n)
    {
        res += min(a[pos].first, m)*a[pos].second/_m;
        m -= min(a[pos].first, m);
        pos++;
    }
    return res;
}

bool cmp(pair<ll,  ll> x1, pair <long double, long double> x2)
{
    return x1.second < x2.second;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first, r += a[i].first;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second;
    sort (a+1, a+n+1, cmp);
    while (r - l > 0.00000001)
    {
        mid = (r+l)/2;
        long double h = calc(mid);
        cout << l << " " << r << endl;
        if (h > t)
            r = mid;
        else l = mid;
    }
    /*if (a[1].first == 963663)
        return cout << mid << " " <<  calc(mid), 0;*/
    if (fabs(calc(mid)-t) > 0.0000001)
        return cout << 0, 0;
    cout << fixed << setprecision(7) << mid;
    return 0;
}
