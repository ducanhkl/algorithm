#include <bits/stdc++.h>

using namespace std;

int e;
int dn[10001], ds[10001], dk[10001];

int main()
{
    for (int i = 0; i < 10001; i++)
        dn[i] = ds[i] = dk[i] = 98765432;
    cin >> e;
    for (int i = 1; i <= e; i++)
        for (int j = sqrt(i); j > 0; j--)
            if (i%j == 0)
    {
        dn[i] = j + i/j;
        ds[i] = min(j, i/j);
        dk[i] = 1;
        break;
    }
    for (int i = 2; i <= e; i++)
        for (int j = 1; j <= i/2; j++)
    {
        int n = dn[j] + dn[i-j];
        int s = ds[j] + ds[i-j];
        int k = dk[j] + dk[i-j];
        if (n < dn[i] || ( n == dn[i] && s < ds[i]) || (n == dn[i] && s == ds[i] && k < dk[j]))
        {
            dn[i] = n;
            ds[i] = s;
            dk[i] = k;
        }
    }
    cout << dn[e] << " " << ds[e] << " "  << dk[e];
    return 0;
}
