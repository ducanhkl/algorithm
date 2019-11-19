#include <bits/stdc++.h>
#define maxn 10000006

using namespace std;

const long long mod = 1000000007;
long long p[maxn], ans;
int t, x, y;

long long fast_pow(long long x, int y)
{
    if (y == 1)
        return x;
    if (y == 0)
        return 1;
    long long res = fast_pow(x, y/2);
    if (y%2)
        return ((res*res)%mod*x)%mod;
    return (res*res)%mod;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    p[0] = 1;
    for (int i = 1; i < maxn; i ++)
        p[i] = (p[i-1]*i)%mod;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        y --;
        ans = fast_pow(2LL, y);
        for (int i = 2; i*i <= x; i++)
            if (x%i == 0)
        {
            int cnt = 0;
            while (x%i == 0)
                cnt ++, x /= i;
            ans = (ans*(p[cnt+y]*(fast_pow(p[cnt]*p[y]%mod, mod-2))%mod)%mod);
        }
        if (x > 1)
            ans = ans*(y+1)%mod;
        cout << ans << endl;
    }
    return 0;
}
