#include <bits/stdc++.h>

using namespace std;

long long s, x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s >> x;
    long long z = (s-x);
    if (z < 0 || z&1 || (z/2)&x)
        cout << 0;
    else
        cout << ((1LL<<(__builtin_popcountll(x)))-2*(s==x));
    return 0;
}
