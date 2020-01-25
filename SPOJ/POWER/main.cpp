#include <bits/stdc++.h>

using namespace std;

const long double limit = 0.0000000000001;

int t;
long double l, r, x1, x2;

int main()
{
    //freopen("inp.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    cin >> t;
    int dem = 1;
    while (t--)
    {
        cin >> l >> r;
        for (double k = 64; k >= 1; k--)
        {
            x1 = exp(log(l)/(long double)k);
            x2 = exp(log(r)/(long double)k);
            if (x2 >= ceil(x1))
            {
                printf("Case #%d: %.0f \n", dem, k);
                dem ++;
                break;
            }
        }
    }
    return 0;
}
