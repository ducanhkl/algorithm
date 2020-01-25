#include <bits/stdc++.h>

using namespace std;

long long l, r, x, y, ans = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> l >> r >> x >> y;
    long long t = y/x;
    for (int i = 1; i <= sqrt(t); i++)
        if (t%i == 0)
    {
        long long j = (t/i)*x;
        long long _i = i*x;
        if (__gcd(_i, j) != x || _i*j/x != y)
            continue;
        if (_i != j && _i >= l && _i <= r && j >= l && j <= r)
            ans += 2;
        if (_i == j && _i >= l && _i <= r && j >= l && j <= r)
            ans ++;
    }
    cout << ans;
    return 0;
}
