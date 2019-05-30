#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000006
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

ll n, q, p, m, d ,ans = LONG_LONG_MAX;
ll f[10*maxn+10], t[10*maxn], dd[10*maxn], a[10*maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    reset(f), reset(dd), reset(t);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> d;
    cin >> p >> q >> m;
    for (ll i = 1; i <= n; i++)
        a[i] = (p*i)%m + q + i*d;
    for (int i = n+1; i <= 2*n; i++)
        a[i] = a[i-n] + (i-1)*d;
    f[0] = LONG_LONG_MAX, t[0] = 0;
    int ib = 1, ie=1;
    for (int i = 1; i <= n; i++)
        if (f[1] < a[i])
            f[1] = a[i], t[1] = i;
    dd[1] = f[ib];
    for (int i = n+1; i <= 2*n; i++)
        {
            while(a[i] > f[ie])
                ie --;
            f[++ie] = a[i];
            t[ie] = i;
            if (ie < ib) ib = ie;
            while (t[ie] - t[ib] > n)
                ib ++;
            dd[i-n+1] = f[ib];
        }
    for (int i = 1; i <= n; i++)
        ans = min(ans, dd[i] - (i-1)*d);
    cout << ans;
    return 0;
}
