#include <bits/stdc++.h>

using namespace std;

long long d, k, a, b, t;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> d >> k >> a >> b >> t;
    long long t1 = a*k+t, t2 = b*k;
    if (d <= k)
    {
        if (a<b)
            cout << d*a;
        else cout << d*b;
        return 0;
    }
    if (d%k == 0)
    {
        long long tx = d/k;
        long long ans = d*a + (tx-1)*t;
        ans = min(ans, k*a+(d-k)*b);
        if (d > 2*k)
            ans = min(ans, k*a+(d-2*k)*b+t+k*a);
        cout << ans;
        return 0;
    }
    long long tx = d/k, du = d%k;
    long long ans = tx*k*a+tx*t+du*a;
    ans = min(ans, k*a+(d-k)*b);
    if (d > 2*k)
        ans = min(ans, k*a+(d-2*k)*b+t+k*a);
    cout << ans;
    return 0;
}
