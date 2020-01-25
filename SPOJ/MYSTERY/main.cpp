#include <bits/stdc++.h>
#define MOD 20122007
using namespace std;

long long a;
long long ans = 1;
long long fast_pow(long long x, int y)
{
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    if (y%2)
        return ((res*res%MOD)*x)%MOD;
    else return (res*res)%MOD;
}
int main()
{
    cin >> a;
    for (int i = 1; i < sqrt(a); i++)
        if (a%i == 0)
    {
        ans = (ans*(fast_pow(3, i)-1+MOD))%MOD;
        ans = (ans*(fast_pow(3, a/i)-1+MOD))%MOD;
    }
    if (sqrt(a)*sqrt(a) == a)
        ans = (ans*(fast_pow(3, sqrt(a))-1+MOD))%MOD;
    cout << ans;
    return 0;
}
