#include <bits/stdc++.h>
#define mod 1000000007
#define maxn 300000

using namespace std;


long long a[maxn], dem1 = 0, dem2 = 0, p[maxn];
string s;
long long ans = 0;

long long fast_pow(long long x, long long  y)
{
    if (y == 1)
        return x%mod;
    long long res = fast_pow(x, y/2);
    res = (res*res)%mod;
    if (y%2)
        return (res*x)%mod;
    return res%mod;
}
long long calc(int x, int y)
{
    if (x < y)
        return 0;
    return (p[x]*fast_pow(p[x-y]*p[y]%mod, mod-2))%mod;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    p[0] = 1;
    for (long long i = 1; i < maxn; i++)
        p[i] = (p[i-1]*i)%mod;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '(')
            a[i+1] = 1;
        else a[i+1] = 0, dem2 ++;
    int n = s.length();
    for (int i = 1; i <= n; i++)
        if (a[i] == 1)
            {
                dem1 ++;
                //cout << calc(dem1 + dem2 - 1, dem1) << endl;
                ans = (ans + calc(dem1 + dem2 - 1, dem1))%mod;
            }
        else dem2 --;
    cout << ans;
    return 0;
}
