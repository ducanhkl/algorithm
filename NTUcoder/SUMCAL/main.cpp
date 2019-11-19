#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000006

using namespace std;

const long long M = 1e9+7;
int f[1000007];
int n;
ll ans = 1;
int a[maxn], b[maxn];

ll calc(int x, int y)
{
    if (y == 1)
        return x;
    ll k = calc(x, y/2);
    if (y%2 == 0)
        return (k*k)%M;
    else return ((((k*k)%M)*x)%M);
}
ll tinh(ll x, ll y)
{
    ll res1 = (calc(x,y+1)-x+M)%M;
    ll res2 = calc(x-1, M-2);
    return (res1*res2)%M;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        ans = 1;
        memset(f, 0, sizeof(f));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <=n; i++)
            cin >> b[i];
        for (int i = 1; i <= n; i++)
            f[a[i]] += b[i];
        for (int i = 2; i < 1e6; i++)
            if (f[i] != 0)
                ans = (ans*tinh(i, f[i]))%M;
        cout << ans << endl;
    }
    return 0;
}
