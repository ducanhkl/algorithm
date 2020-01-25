#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define MOD 1000000007
#define maxn 10000007

using namespace std;

ll a[maxn], fact[maxn], dp[maxn], res[maxn];
int n, k;

ll fp(ll x, ll y)
{
    if (y == 1)
        return x%MOD;
    ll d = fp(x, y/2)%MOD;
    if (y%2)
        return (((d*d)%MOD)*x)%MOD;
    else return d*d%MOD;
}/*
ll nCk(ll x, ll y)
{
    ll h = fp(p[x-y]*p[y]%MOD, MOD-2)%MOD;
    return (p[x]*h)%MOD;
}
int fp(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = 1LL * r * a % MOD;
    a = 1LL * a * a % MOD;
    b >>= 1;
  }
  return r;
}
*/
int nCk(int x, int y)
{
    ll h = fp(fact[x-y]*fact[y]%MOD, MOD-2)%MOD;
    return (fact[x]*h)%MOD;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i]+=a[i-1];
    if (a[n] == 0)
    {
        fact[0] = 1;
        for (ll i = 1; i <= n; i++)
            fact[i] = i*fact[i-1]%MOD;
        //cout << nCk(4, 3) << endl;
        int dem = 0;
        for (int i = 1; i <= n; i++)
            dem += a[i] == 0;
        if (dem < k)
            return cout << 0, 0;
        else return cout << nCk(dem-1, k-1), 0;
    }
    memset(dp, 0, sizeof(dp));
    ll s = a[n]/k;
    if (a[n]%k != 0)
        return cout << 0, 0;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        if (a[i]%s == 0)
    {
        int id = a[i]/s;
        dp[id] = (dp[id] + dp[id-1])%MOD;
    }
    cout << dp[k-1];
    return 0;
}
