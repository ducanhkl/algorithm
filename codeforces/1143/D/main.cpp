#include <bits/stdc++.h>

using namespace std;

long long n, k, a, b;
long long resmin = LONG_LONG_MAX, resmax = 0;

void calc(long long x)
{
    for (long long i = x; i <= n*k; i += k)
    {
        long long res = n*k/__gcd(n*k, i);
        resmin = min(resmin, res);
        resmax = max(resmax, res);
    }
    return ;
}

int main()
{
    cin >> n >> k >> a >> b;
    long long l = k-a-b;
    calc(l);
    l = abs(b-a);
    calc(l);
    l = a+b;
    calc(l);
    cout << resmin << " " << resmax;
    return 0;
}
