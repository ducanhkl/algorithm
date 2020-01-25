#include <bits/stdc++.h>

using namespace std;

double a[200];
double tong = 0;
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], tong += a[i];
    sort(a+1, a+n+1);
    if (tong/n>= 4.5)
        return cout << 0, 0;
    for (int i = 1; i <= n; i++)
    {
        tong += 5-a[i];
        if (tong/n >= 4.5)
            return cout << i, 0;
    }
    return 0;
}
