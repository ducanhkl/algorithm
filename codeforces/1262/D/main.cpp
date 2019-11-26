#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--)
    {
        int resx = 0, resy = INT_MAX;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            resx = max(resx, x);
            resy = min(resy, y);
        }
        cout << max(0, resx-resy) << endl;
    }
    return 0;
}
