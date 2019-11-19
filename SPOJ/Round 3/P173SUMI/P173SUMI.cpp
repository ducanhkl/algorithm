#include <bits/stdc++.h>

using namespace std;

long long a, b;

int d1[4], d2[4];

int main()
{
    cin >> a >> b;
    while (a%5 == 0)
        a= a/5, d1[1] ++;
    while (a%3 == 0)
        a = a/3, d1[2] ++;
    while (a%2 == 0)
        a = a/2, d1[3] ++;
    while (b%5 == 0)
        b = b/5, d2[1] ++;
    while (b%3 == 0)
        b = b/3, d2[2] ++;
    while (b%2 == 0)
        b = b/2, d2[3] ++;
    if (a != b)
        cout << -1;
    else cout << abs(d1[1] - d2[1]) + abs(d1[2] -  d2[2]) + abs(d1[3] - d2[3]);
    return 0;
}
