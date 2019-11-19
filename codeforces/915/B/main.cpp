#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    int n, pos, l, r;
    //freopen("inp.txt", "r", stdin);
    //ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    cin >> pos;
    cin >> l;
    cin >> r;
    if (l == 1 && r == n)
        return cout << 0, 0;
    if (l == 1)
        return cout << abs(r - pos) + 1, 0;
    if (r == n)
        return cout << abs(l - pos) + 1, 0;
    if (pos < l)
        return cout << l - pos + 1 + (r - l) + 1, 0;
    if (pos > r)
        return cout << pos - r + 1 + (r-l) + 1, 0;
    cout << min(pos - l, r - pos) + 1 + (r-l) + 1;
    return 0;
}
