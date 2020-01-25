#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000006

using namespace std;

ll n, k, x, d = 0;
ll a[maxn], b[maxn];
ll ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> x >> k;
    for (int i = 1; i <= n; i++)
            cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        ll u = (a[i] - 1)/x;
        ll r = u+k;
        ans += lower_bound(a+1, a+n+1, (r+1)*x) - lower_bound(a+1, a+n+1, max(a[i], r*x));
    }
    cout << ans;
    return 0;
}
