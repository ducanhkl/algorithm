#include <bits/stdc++.h>

using namespace std;

long long a, b, x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> x >> y;
    long long ucln = __gcd(x, y);
    x /= ucln; y /= ucln;
    cout << min(a/x, b/y);
    return 0;
}
