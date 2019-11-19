#include <bits/stdc++.h>

using namespace std;

long long n;
const long long mod = 1e9+7;

long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    res = (res*res)%mod;
    if (y%2)
        return res*x%mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cout << fast_pow(3, n-1);
    return 0;
}
