#include <bits/stdc++.h>

using namespace std;

long long const mod = 1e9+7;
long long x = 2, y, a;
bool even = 0, out = 1;
int n;
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
    else return res;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a > 1)
            out = 0;
        if (a%2==0)
            even = 1;
        x = fast_pow(x, a);
    }
    if (out)
        return cout << "0/1", 0;
    x = x*fast_pow(2, mod - 2)%mod;
    if (even)
        y = (x+1)*fast_pow(3, mod-2)%mod;
    else y = (mod+x-1)*fast_pow(3, mod-2)%mod;
    cout << y << '/' << x;
    return 0;
}
