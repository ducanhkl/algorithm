#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        int a, b, c, ans = 0;
        cin >> a >> b >> c;
        int t = min(b, c/2);
        b -= t;
        c -= 2*t;
        ans += 3*t;
        t = min(a, b/2);
        ans += 3*t;
        cout << ans << endl;
    }
    return 0;
}
