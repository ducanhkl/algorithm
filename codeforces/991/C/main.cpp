#include <bits/stdc++.h>

using namespace std;

long long l = 1, r = 1e18, n, s, ans = 0;

bool check(long long k)
{
    long long sl = 0, m = n;
    bool dd = 1;
    while (m != 0)
        if (dd)
            sl += min(m, k), dd = !dd, m -= min(m, k);
        else
        {
             m = m - m/10;
             dd = !dd;
        }
    return sl >= s;
}

int main()
{
    cin >> n;
    if (n%2)
        s = n/2 + 1;
    else s = n/2;
    while (l<=r)
    {
        long long mid = (l+r)/2LL;
        if (check(mid))
            ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}
