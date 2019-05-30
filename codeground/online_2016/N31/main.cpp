#include <bits/stdc++.h>

using namespace std;

unsigned long long mi, ma;
int t, k;

void make(unsigned long long x, int y)
{
    if (y > k)
        return;
    if (y == k)
    {
        ma = max(ma, x);
        mi = min(mi, x);
    }
    if (x > 1 && ((x-1)%3==0) && ((x-1)/3)%2 != 0 && (x-1)/3 != 1)
        make((x-1)/3, y+1);
    make(x*2, y+1);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    int test = 0;
    while (t--)
    {
        mi = LONG_LONG_MAX;
        ma = 0;
        cin >> k;
        make(1, 0);
        cout << "Case #" <<  ++test << endl;
        cout << mi << " " << ma << endl;
    }
    return 0;
}
