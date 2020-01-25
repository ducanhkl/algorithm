#include <bits/stdc++.h>
#define MOD 76213

using namespace std;

long long n, p[10001];
long long res = 0;

long long fast_pow(long long x, long long y)
{
    if (y == 1)
        return x;
    long long ans = fast_pow(x, y/2);
    if (y%2)
        return (ans*ans*x)%MOD;
    else return ans*ans%MOD;
}
long long c(long long x,long long y)
{
    long long fp = fast_pow((p[x]*p[y-x]%MOD), MOD-2);
    long long ans = p[y]*fp%MOD;
    return ans;
}
int main()
{
    cin >> n;
    p[0] = 1;
    for (long long i = 1; i <= 10000; i++)
        p[i] = p[i-1]*i % MOD;
    for (long long i = 1; i <= n; i++)
    {
        long long l = c(i, n)*p[n-i]%MOD;
        if (i % 2 == 0)
            res = (res - l + MOD)%MOD;
        else
            res = (res + l)%MOD;
    }
    cout << (p[n] - res + 1000*MOD ) % MOD;
    return 0;
}
