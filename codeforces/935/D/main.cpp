#include <bits/stdc++.h>
#define maxn 1000006
#define mod 1000000007

using namespace std;


long long p[maxn], n, m, a[maxn], b[maxn];

long long fast_pow(long long x, long long y)
{
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    if (y%2)
        return ((res*res)%mod*x%mod)%mod;
    else return (res*res)%mod;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    p[n+1] = 0;
    long long inf = fast_pow(m, mod-2);
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == b[i] && a[i] == 0)
            p[i] = (p[i+1]*inf%mod + ((m-1)*m/2%mod*inf%mod)%mod*inf%mod)%mod;
        else if (a[i] == 0)
            p[i] = ((m-b[i])*inf%mod + p[i+1]*inf%mod)%mod;
        else if (b[i] == 0)
            p[i] = ((a[i]-1)*inf%mod + p[i+1]*inf%mod)%mod;
        else if (a[i] > b[i])
            p[i] = 1;
        else if (a[i] < b[i])
            p[i] = 0;
        else p[i] = p[i+1];
    }
    cout << p[1];
    return 0;
}
