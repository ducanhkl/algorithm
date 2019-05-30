#include <bits/stdc++.h>

using namespace std;

unsigned long long l, r, x, res;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> l >> r >> x;
    long double k = log(l)/log(x);
    res = 1;
    for (int i = 1; i < k; i++)
        res = res*x;
    int dem = 0;
    if (res >= l)
        cout << res << " ", dem ++;
    while (res <= r/x)
    {
        res *= x;
        if (res >= l)
            cout << res << " ", dem ++;
    }
    if (dem == 0)
        cout << -1;
    return 0;
}
