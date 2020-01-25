#include <bits/stdc++.h>

using namespace std;

long double a, b, c, d, tt, vv;
const long double eps = 0.000000000001;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> d;
        tt = log2(a), vv = log2(c);
        if ((b/d)*tt - vv < -eps)
            {
                cout << '<' << endl;
                continue;
            }
        if ((b/d)*tt - vv > eps)
            {
                cout << '>' << endl;
                continue;
            }
        cout << '=' << endl;
    }
    return 0;
}
