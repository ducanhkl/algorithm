#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000006

using namespace std;

ll mina[maxn], maxa[maxn], smina[maxn], smaxa[maxn], res[maxn];
ll ans = LONG_LONG_MIN;
ll n, a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    //ios_base::sync_with_stdio(0);
    scanf(" %lld", &n);
    for (int i = 1; i <= n; i++)
        scanf(" %lld", &a[i]);
    long long t = 0;
    for (int i = 0; i <= n+1; i++)
        mina[i] = LONG_LONG_MAX, maxa[i] = LONG_LONG_MIN;
    for (int i = n; i >= 1; i--)
    {
        t += a[i];
        smina[i] = smina[i+1];
        smaxa[i] = smaxa[i+1];
        mina[i] = mina[i+1];
        maxa[i] = maxa[i+1];
        if (mina[i] > t)
            {
                mina[i] = t;
                smina[i] = 1;
            }
        else if (mina[i] == t)
            smina[i]++;
        if (maxa[i] < t)
            {
                maxa[i] = t;
                smaxa[i] = 1;
            }
        else if (maxa[i] == t)
            smaxa[i]++;
    }
    t = 0;
    for (int i = 1; i < n; i++)
    {
        t += a[i];
        ll t1 = abs(mina[i+1] - t);
        ll t2 = abs(maxa[i+1] - t);
        if (t1==t2)
            a[i] = t1, res[i] += smina[i+1] + smaxa[i+1];
        if (t1 < t2)
            a[i] = t2, res[i] = smaxa[i+1];
        if (t1 > t2)
            a[i] = t1, res[i] = smina[i+1];
        ans = max(ans, max(t1, t2));
    }
    int dem = 0;
    for (int i = 1; i < n; i++)
        if (a[i] == ans)
            dem += res[i];
    cout << ans << " " << dem;
    return 0;
}
