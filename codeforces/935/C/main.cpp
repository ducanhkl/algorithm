#include <bits/stdc++.h>

using namespace std;


struct point
{
    long double x, y;
} p1, p2;
long double r;

long double d(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> r >> p1.x >> p1.y >> p2.x >> p2.y;
    if (d(p1, p2) - r > 0)
    {
        cout << fixed << setprecision(10) << p1.x << " " << p1.y << " " << r;
        return 0;
    }
    long double ra = (d(p1,p2)+r)/2;
    if (d(p1, p2) == 0)
        cout << fixed << setprecision(6) << p2.x + ra << " " << p2.y << " " << ra;
    else
        cout << fixed << setprecision(6) << p2.x + ra*(p1.x-p2.x)/d(p1, p2) << " " << p2.y + ra*(p1.y-p2.y)/d(p1, p2) << " " << ra;
    return 0;
}
