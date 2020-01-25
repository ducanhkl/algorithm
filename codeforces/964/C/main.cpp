#include <bits/stdc++.h>

using namespace std;


const long long MOD = 1e9+9;

long long a, b, n, k, p, q, res = 0;

long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long ans = fast_pow(x, y/2);
    ans = (ans*ans)%MOD;
    if (y%2)
        return (ans*x)%MOD;
    return ans;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> k;
    for (int i = 0; i < k; i++)
    {
        char x;
        cin >> x;
        if (x == '+')
            res = (res + fast_pow(a,n-i)*fast_pow(b, i)%MOD)%MOD;
        else res = (res - fast_pow(a, n-i)*fast_pow(b, i)%MOD + MOD*MOD)%MOD;
    }
    p = fast_pow(a, k*(MOD-2)) * fast_pow(b, k)%MOD;
    q = (n+1)/k;
    if (p == 1)
        cout << q*(res)%MOD;
    else
        cout << ((res*(fast_pow(p, q)-1))%MOD*(fast_pow(p-1, MOD-2)%MOD))%MOD;
    return 0;
}
