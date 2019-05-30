#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
long long x1, y1, x2, y2, n;
long long px[maxn], py[maxn];
long long ans = -1;

bool check(long long p)
{
    long long step = p/n;
    long long stepx = step*px[n], stepy = step*py[n];
    stepx += x1;
    stepy += y1;
    stepx += px[p%n];
    stepy += py[p%n];
    if (abs(x2-stepx) + abs(y2-stepy) <= p)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    memset(px, 0, sizeof(px));
    memset(py, 0, sizeof(py));
    for (int i = 1; i <= n; i++)
    {
        int cx, cy;
        char x;
        cin >> x;
        if (x == 'U')
        {
            cx = 0;
            cy = 1;
        }
        if (x == 'D')
        {
            cx = 0;
            cy = -1;
        }
        if (x == 'L')
        {
            cx = -1;
            cy = 0;
        }
        if (x == 'R')
        {
            cx = 1;
            cy = 0;
        }
        px[i] = px[i-1] + cx;
        py[i] = py[i-1] + cy;
    }
    long long l = 0, r = 1e15;
    while (l <= r)
    {
        long long mid = (l+r) >> 1;
        if (check(mid))
            ans = mid, r = mid-1;
        else
            l = mid+1;
    }
    cout << ans;
    return 0;
}
