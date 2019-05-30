#include <iostream>

using namespace std;

long long const mod = 123456789;

long long n;

long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    res = res*res%mod;
    if (y%2)
        return res*x%mod;
    else
        return res;
}

int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << fast_pow(2LL, n-1) << endl;
    }
    return 0;
}
