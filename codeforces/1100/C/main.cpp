/*
#include <bits/stdc++.h>

using namespace std;

const long double pi = acos(-1);
long double l = 0, r = 1e18, mid, alpha, n, h;

long double calc(long double x)
{
    long double e = x+h;
    return e*sin(alpha*pi/360)*2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> h;
    alpha = 180*(n-2)/n;
    alpha /= 2.0;
    alpha = 180.0-2.0*alpha;
    for (int i = 1; i <= 200; i++)
    {
        mid = (l+r)/2;
        if (calc(mid) > 2*mid)
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(10) << mid;
    return 0;
}
*/
