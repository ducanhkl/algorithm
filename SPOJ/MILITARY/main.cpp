#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e3+100;

struct point
{
    int x, y;
} a[maxn];

void operator -= (point &x, point y)
{
    x.x -= y.x;
    x.y -= y.y;
}

int ccw(point x, point y, point z)
{
    point v1 = y;
    point v2 = z;
    v1 -= x;
    v2 -= x;
    return v2.y*v1.x > v2.x*v1.y;
}

int ans = 0;
int s[maxn], dd[maxn], n;



void solve()
{
    int now = 1, top = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top > 1 && ccw(a[s[top]], a[s[top-1]], a[i]))
            top --;
            s[++top] = i;
    }
    int t = top+1;
    for (int i = n; i >= 1; i--)
    {
        while (top > t && ccw(a[s[top]], a[s[top-1]], a[i]))
            top --;
        s[++top] = i;
    }
    for (int i = 1; i <= n; i++)
        dd[i] = 0;
    for (int i = 1; i <= top; i++)
        dd[s[i]] = 1;
    int newn = 0;
    for (int i = 1; i <= n; i++)
        if (dd[i] == 0)
        {
            a[++newn] = a[i];
        }
    n = newn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i].x >> a[i].y;
        }
    sort (a+1, a+n+1, [] (point x, point y) {
        if (x.x == y.x)
            return x.y < y.y;
        return x.x < y.x;
    });
    while (n > 2)
    {
        ans ++;
        solve();
    }
    cout << ans;
    return 0;
}