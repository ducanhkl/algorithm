#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;
map <int, long long> dd;
int x, y;

long long fast_pow(long long x, long long y)
{
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    if (y%2)
        return ((res*res%mod)*x)%mod;
    return res*res%mod;
}
long long calc(int t)
{
    long long res = 1;
    if (dd[t])
        return t;
    for (int i = 2; i < sqrt(t); i++)
        if (t%i == 0)
            res = (res+calc(t/i)+calc(i))%mod;
    if (sqrt(t)*sqrt(t) == t)
        res = (res+calc(sqrt(t)))%mod;
    res = (fast_pow(2, t-1)-res+mod*mod)%mod;
    return dd[t] = res;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> x >> y ;
    if (y%x != 0)
        return cout << 0, 0;
    dd[1] = 1;
    cout << calc(y/x);
    return 0;
}
