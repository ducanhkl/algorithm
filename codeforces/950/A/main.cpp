#include <bits/stdc++.h>

using namespace std;

int l, r, a;

int main()
{
    cin >> l >> r >> a;
    if (l == r)
        return cout << l+r+(a/2)*2, 0;
    if (l < r)
        swap(l, r);
    if (r + a > l)
        cout << 2*l + (((r+a)-l)/2)*2;
    else cout << (r+a)*2;
    return 0;
}
