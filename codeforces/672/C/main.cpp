#include <bits/stdc++.h>

using namespace std;

const long double maxc = 1e18;
const int maxn = 1e5+100;
typedef pair <long double, long double> pii;
long double ax, ay, bx, by, tx, ty, minlr = maxc, minl = maxc, minr = maxc;
long double ans = 0;
pii a[maxn];
int n;

long double sqr(long double x)
{
    return x*x;
}

long double dis(pii x, pii y)
{
    return sqrt(sqr(x.first-y.first) + sqr(x.second-y.second));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i].first >> a[i].second;
            long double d = dis({tx, ty}, a[i]);
            ans += 2*d;
            long double l = dis({ax, ay}, a[i])-d;
            long double r = dis({bx, by}, a[i])-d;
            minlr = min(minlr, min(minl+r, minr+l));
            minl = min(minl, l);
            minr = min(minr, r);
        }
    cout << fixed << setprecision(10) << ans+min(minlr, min(minl, minr));
    return 0;
}
