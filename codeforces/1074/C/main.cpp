#include <bits/stdc++.h>

using namespace std;

struct point
{
    int x, y;
} p[300006];

int xl = INT_MAX, yl = INT_MAX, yr = INT_MIN, xr = INT_MIN, n;
int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
        xl = min(xl, p[i].x);
        yl = min(yl, p[i].y);
        xr = max(xr, p[i].x);
        yr = max(yr, p[i].y);
    }
    for (int i = 1; i <= n; i++)
    {
        res = max(res, abs(p[i].x-xl)+abs(p[i].y-yl));
        res = max(res, abs(p[i].x-xl)+abs(p[i].y-yr));
        res = max(res, abs(p[i].x-xr)+abs(p[i].y-yl));
        res = max(res, abs(p[i].x-xr)+abs(p[i].y-yr));
    }
    cout << res*2 << " ";
    for (int i = 4; i <= n; i++)
        cout << 2*(xr-xl+yr-yl) << " ";
    return 0;
}
