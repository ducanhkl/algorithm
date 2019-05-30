#include <bits/stdc++.h>

using namespace std;
struct point{
    long double x, y;
};

point a[1000];
int n, dem = 0;
int dd[300];

int ccw(point p1, point p2, point p3)
{
    long double a1 = p2.x - p1.x;
    long double b1 = p2.y - p1.y;
    long double a2 = p3.x - p2.x;
    long double b2 = p3.y - p2.y;
    long double t = a1*b2 - a2*b1;
    if (t > 0)
        return 1;
    if (t < 0)
        return -1;
    return 0;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= n; i++)
        for (int j = i-1; j >= 1; j--)
            for (int k = j-1; k >= 1; k--)
    {
        if (ccw(a[i], a[j], a[k]) != 0)
            dd[i]++, dd[j] ++, dd[k]++, dem ++;
    }
    int minn = 1;
    for (int i = 1; i <= n; i++)
        if (dd[i] < dd[minn])
            minn = i;
    cout << dem << " " << minn;
    return 0;
}
