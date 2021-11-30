#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
        {
            cout << x + y;
        } else
        {
            cout << (y % x) / 2 + (y / x) * x;
        }
        cout << endl;
    }
    return 0;
}
