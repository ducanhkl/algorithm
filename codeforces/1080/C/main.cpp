#include <bits/stdc++.h>

using namespace std;

long long n, m, x1, x2, x3, x4, y1,y2, y3, y4;

long long calc(long long u, long long v)
{
    return u/v+(int)(u%v>0);
}

long long  counterw(long long u, long long v)
{
    return calc(u, 2)*calc(v, 2) + (u/2)*(v/2);
}

long long w(long long a, long long b, long long c, long long d)
{
    return counterw(c, d) - counterw(a-1, d) - counterw(c, b-1) + counterw(a-1, b-1);
}

long long b(long long a, long long b, long long c, long long d)
{
    return (c-a+1)*(d-b+1) - w(a, b, c, d);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    int t;
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        long long cntw, cntb;
        cin >> m >> n;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >>y4;
        cntw = w(1, 1, n, m);
        cntb = b(1, 1, n, m);
        cntw += b(x1, y1, x2, y2);
        cntb -= b(x1, y1, x2, y2);
        cntw -= w(x3, y3, x4, y4);
        cntb += w(x3, y3, x4, y4);
        if (max(x1, x3) <= min(x2, x4) && max(y1, y3) <= min(y2, y4))
        {
            cntw -= b(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4));
            cntb += b(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4));
        }
        cout << cntw << " " << cntb << endl;
    }
    return 0;
}
