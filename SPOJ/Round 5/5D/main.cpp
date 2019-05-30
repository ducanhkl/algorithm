#include <bits/stdc++.h>

using namespace std;

long long a, b, kq = 0;
long long ucln(long long x, long long y)
{
    long long r;
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int main()
{
    cin >> a >> b;
    long long h = ucln(a, b);
    long long x = b/a;
    long long l = ((b-x*a)/h);
    b -= l*h;
    kq += l;
    while (b > a && b%a != 0)
        b -= h, kq ++;
    h =ucln(a, b);
    kq += b/h;
    cout << kq;
    return 0;
}
