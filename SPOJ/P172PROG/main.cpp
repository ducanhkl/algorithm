#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

const long double pi = acos(-1);
long long a[maxn], ans = 0, p[maxn], t[maxn];
int n;

long double get(int x)
{
    long long res = 0;
    for (;x>0; x -= (x&(-x)))
        res = max(res, t[x]);
    return res;
}

void update(int x, long long y)
{
    for (; x < maxn; x += (x&(-x)))
        t[x] = max(t[x], y);
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long r, h;
        cin >> r >> h;
        a[i] = r*r*h;
        p[i] = a[i];
    }
    sort(p+1, p+n+1);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(p+1, p+n+1, a[i]) - p;
    for (int i = 1; i <= n; i++)
    {
        long long res = get(a[i] - 1);
        update(a[i], res+p[(int)a[i]]);
        ans = max(ans, res+p[(int)a[i]]);
    }
    cout << fixed << setprecision(8) << ans*acos(-1);
    return 0;
}
