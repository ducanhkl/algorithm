#include "bits/stdc++.h"

using namespace std;

const int maxn = 54000;

struct point
{
    long long x, y;
} p[maxn];

int n;
int s[maxn], dd[maxn];

bool ccw(point x, point y, point z)
{
    point v1 = {y.x - x.x, y.y - x.y};
    point v2 = {z.x - x.x, z.y - x.y};
    return v2.y*v1.x > v2.x*v1.y;
}

void convexhull()
{
    sort (p+1, p+n+1, [] (point x, point y) { if (x.x == y.x)x.y < y.y;return x.x < y.x; });
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top > 2 && ccw(p[s[top-1]], p[s[top]], p[i]))
            top--;
        s[++top] = i;
    }
    int t = top+1;
    for (int i = n; i >= 1; i--)
    {
        while (top > t && ccw(p[s[top-1]], p[s[top]], p[i]))
            top--;
        s[++top] = i;
    }
    for (int i = 1; i <= n; i++)
        dd[i] = 0;
    int newn = 0;
    for (int i = 1; i <= top; i++)
        dd[s[i]] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dd[i] == 1)
            p[++newn] = p[i];
    }
    n = newn;
    return ;
}

long long area(int posx, int posy, int posz)
{
    point x = p[posx], y = p[posy], z = p[posz];
    point v1 = {x.x - y.x, x.y - y.y};
    point v2 = {z.x - y.x, z.y - y.y};
    return  abs(v1.x*v2.y - v1.y*v2.x);
}

void solve()
{
    int a, b, c, ra, rb, rc;
    a = ra = 1;
    b = rb = 2;
    c = rc = 3;
    for (a = 1; a <= n; a++)
    {
        if (a == b)
            b = b%n+1;
        if (b == c)
            c = c%n + 1;
        while (true)
        {
            while (area(a, b, c) <= area(a, b, c%n + 1))
                c = (c%n) + 1;
            if (area(a, b, c) <= area(a, b%n+1, c))
            {
                b = b%n + 1;
                continue;
            }
            break;
        }
        if (area(a, b, c) > area(ra, rb, rc))
        {
            ra = a;
            rb = b;
            rc = c;
        }
    }
    cout << fixed << setprecision(10) << (long double)area(ra, rb, rc)/2 << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    while (cin >> n)
    {
        if (n == -1)
            exit(0);
        for (int i = 1; i <= n; i++)
            cin >> p[i].x >> p[i].y;
        convexhull();
        solve();
    }
}