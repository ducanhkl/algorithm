#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int res = k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        res = __gcd(res, x);
    }
    int ans = 0;
    cout << k/res << endl;
    while (ans < k)
    cout << ans << " ", ans += res;
    return 0;
}
