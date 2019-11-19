#include <bits/stdc++.h>

using namespace std;

unsigned long long k, l, r, ans, g;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> k;
    l = 1, r = 1e18;
    while (l != r)
    {
        g = (l+r)>>1;
        ans = g - (unsigned long long)sqrt(g);
        if (ans >= k)
            r = g;
        else l = g+1;
    }
    cout << l;
    return 0;
}
