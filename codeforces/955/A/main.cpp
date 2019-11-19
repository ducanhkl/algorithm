#include <bits/stdc++.h>

using namespace std;

long double hh, mm, h, d, c, n, ans;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> hh >> mm;
    cin >> h >> d >> c >> n;
    if (hh < 20)
    {
        ans = 0.8*ceil((((20-hh-1)*60 + (60-mm))*d + h)/n)*c;
        ans = min(ans, c*ceil(h/n));
    }
    else
        ans = 0.8*c*ceil(h/n);
    cout << fixed << setprecision(4) << ans;
    return 0;
}
