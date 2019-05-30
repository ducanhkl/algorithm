#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    long double tong = 0;
    int i;
    for (i = 1; i <= 1e7; i++)
    {
        tong += log10(i);
        if (floor(tong) == n-1)
            break;
        if (tong > n)
            return cout << "NO", 0;
    }
    int j = i;
    while (tong < n)
        j ++, tong += log10(j);
    cout << j - i << endl;
    for (int k = i; k < j; k++)
        cout << k << endl;
}
