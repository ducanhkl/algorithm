#include <bits/stdc++.h>

using namespace std;

long long n, k, m;


long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x%m;
    long long res = fast_pow(x, y/2);
    res = res*res%m;
    if (y%2)
        return res*x%m;
    return res%m;
}

long long fast_mul(long long x, long long y, long long mod)
{
    if (y == 0)
        return 0;
    if (y == 1)
        return x%m;
    if (y == 2)
        return x*2%m;
    long long res = fast_mul(x, y/2, mod);
    if (y%2)
        return (res+res+x)%m;
    return (res+res)%m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> k >> m;
        long long tu = 1, mau = 1;
        for (long long i = 1; i <= k; i++)
        {
            long long num2 = i;
            while (num2 % m == 0)
                num2 /= m;
            tu = fast_mul(tu, n-i+1, m);
            mau = fast_mul(mau, num2, m);
        }
        cout << fast_mul(tu, fast_pow(mau, m-2), m) << endl;
    }
}
