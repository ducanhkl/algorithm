#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;


struct point
{
    long double x, y;
} p[maxn];

int n, flag = 0;
long double ans;
long double l = 0, r = 1e16, mid;
const long double eps = 1e-7;


bool can(long double r)
{
    long double ll = -1e16;
    long double rr = 1e16;
    for (int i = 1; i <= n; i++)
    {
        long double b = -2*p[i].x;
        long double ac = p[i].x*p[i].x + p[i].y*p[i].y - 2*p[i].y*r;
        long double delta = b*b-4*ac;
        if (delta-eps<0)
            return false;
        delta = sqrt(delta)/2;
        long double mi = p[i].x-delta;
        long double ma = p[i].x+delta;
        ll = max(ll, mi);
        rr = min(rr, ma);
    }
    if (ll > rr)
        return false;
    return true;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
        if (p[i].y < 0)
            flag |= 1;
        else
            flag |= 2;
    }
    if (flag == 3)
        return cout << -1, 0;
    if (flag == 1)
        for (int i = 1; i<= n; i++)
            p[i].y = -p[i].y;
    for (int i = 1; i <= 400; i++)
    {
        mid = (l+r)/2;
        if (can(mid))
            r = mid, ans = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(10) << l;
    return 0;
}
