#include <bits/stdc++.h>

using namespace std;

long long x, y, ans = 0;

int main()
{
    cin >> x >> y;
    while (y)
    {
        long long g = __gcd(x, y);
        long long tmp  = y/g, mx = 0;
        x /= g;
        for (long long i = 1; i <= sqrt(x); i++)
        {
            if (x%i == 0)
            {
                if (i != 1)
                    mx = max(mx, (tmp/i)*i);
                if (i*i != x)
                    mx = max(mx, (tmp/(x/i))*(x/i));
            }
        }
        ans += tmp - mx;
        y = mx*g;
        x *= g;
    }
    cout << ans;
    return 0;
}
