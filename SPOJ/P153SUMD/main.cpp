#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000006

using namespace std;
ll n, a[maxn], d1[maxn], d2[maxn], dem = 0, t[maxn];
ll ans = 0;
int main()
{
    //freopen("8.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], t[a[i]]++;
    for (int i = 1; i < maxn; i++)
        t[i] += t[i-1];
    for (ll i = 1; i < maxn; i++)
    {
        ll x = t[i] - t[i-1];
        d1[i] = i*x + max(d1[i-2], max(d2[i-2], d2[i-1]));
        d2[i] = max(d1[i-1], d2[i-1]);
    }
    for (int i = 1; i < maxn; i++)
        ans = max(ans, max(d1[i], d2[i]));
    cout << ans;
    return 0;
}
