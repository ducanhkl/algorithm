#include <bits/stdc++.h>

using namespace std;

long double x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> x >> y;
    if (y*log(x) < x*log(y))
        return cout << '<', 0;
    if (y*log(x) > x*log(y))
        return cout << '>', 0;
    cout << '=';
    return 0;
}
