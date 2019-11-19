#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000004

using namespace std;

int n;
ll p, t = 0;
pii a[maxn];
long double res = 0;
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(false);
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        t += a[i].first;
    }
    if (t <= p)
        return cout << -1, 0;
    long double m, l = 0, r = 1e18;
    while (r-l > 1e-8)
    {
        m = (r+l)/2;
        res = 0;
        for (int i = 1; i <= n; i++)
            res += max(a[i].first*m - a[i].second, (long double)0);
        if (res > p*m)
            r = m;
        else l = m;
    }
    cout << (l+r)/2;
    return 0;
}
