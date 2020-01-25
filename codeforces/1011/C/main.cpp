#include <bits/stdc++.h>
#define maxn 3000

using namespace std;

int n;
long double m, a[maxn], b[maxn], ans = INT_MAX, l = 0, r = 1e15;
const long double eps = 1e-9;
const long double eps2 = 1e-13;
bool check(long double x)
{
    long double _x = m+x;
    for (int i = 1; i <= n; i++)
    {
        long double x1;
        if (b[i] != 0)
        {
            x1 = _x/b[i];
            x -= x1;
            _x -= x1;
        }
        if (a[i] != 0)
        {
            x1 = _x/a[i];
            x -= x1;
            _x -= x1;
        }
    }
    return (x-eps2) > 0;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    b[n+1] = b[1];
    b[1] = 0;
    a[n+1] = 0;
    n+=1;
    while (r - l > eps)
    {
        long double mid = (l+r)/2;
        if (check(mid))
            r = mid, ans = mid;
        else l = mid;
    }
    if (ans == INT_MAX)
        return cout << -1, 0;
    cout << fixed << setprecision(10) << ans;
    return 0;
}
