#include <bits/stdc++.h>

using namespace std;


long long n, m;
long long ans = 0;
const long long mod = 1e9+7;

long long bin_pow(long long x, long long y)
{
    if (y == 1)
        return x%mod;
    if (y == 0)
        return 1;
    long long res = bin_pow(x, y/2);
    res = res*res%mod;
    if (y%2)
        return res*x%mod;
    return res;
}

int main()
{
    cin >> n >> m;
    ans = bin_pow(2, m);
    ans = (ans-1+mod)%mod;
    ans = bin_pow(ans, n);
    cout << ans%mod;
    return 0;
}
